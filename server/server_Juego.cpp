/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: usuario
 * 
 * Created on 29 de mayo de 2017, 10:00
 */

#include "server_Juego.h"
#include "server_Mapa.h"
#include "server_AEstrella.h"
#include "server_Unidad.h"
#include "server_FabricaRobots.h"
#include "server_FabricaVehiculos.h"
#include "server_Bloque.h"
#include "server_Edificio.h"
#include <array>
#include <iostream>
#include <time.h>
#include "server_constants.h"
#include "server_FabricaMuniciones.h"
#include "common_SocketException.h"
#include <chrono>
#include <string>
#include "Mensaje.h"

void Juego::inicializarEdificios(int tipo, tinyxml2::XMLElement* padre, 
									std::string nombreXML) {
	
	tinyxml2::XMLElement* edificiosXML = padre->FirstChildElement (nombreXML.c_str());
	tinyxml2::XMLElement* edificioXML = edificiosXML->FirstChildElement ("EDIFICIO");
	for (int i = 0; i < jugadores.size () && i < 4; ++i) {
		int equipo = atoi(edificioXML->FirstChildElement("EQUIPO")->GetText ());
		double x = atof(edificioXML->FirstChildElement("X")->GetText ());
		double y = atof(edificioXML->FirstChildElement("Y")->GetText ());
		std::string id = manejadorIDs.getIDEdificio ();
		Edificio* edificio = fabricaEdificios->getEdificio (tipo,equipo,x,y,id);
		edificios[id] = edificio;
		
		Mensaje mensajeEdificio;
		mensajeEdificio.mensajeDeCrear (edificio,id, edificio->getEquipo ());
		this->enviarMensaje(mensajeEdificio);
		edificioXML = edificioXML->NextSiblingElement ("EDIFICIO");
	}
}

void Juego::inicializarInmovibles(int tipo, tinyxml2::XMLElement* padre, 
								std::string nombreXML, std::string nombreObjetos) {
  	tinyxml2::XMLElement* inmoviblesXML = padre->FirstChildElement (nombreXML.c_str ());
	tinyxml2::XMLElement* inmovibleXML = inmoviblesXML->FirstChildElement (nombreObjetos.c_str());
	for (int i = 0; inmovibleXML != NULL; ++i) {
		double x = atof(inmovibleXML->FirstChildElement("X")->GetText ());
		double y = atof(inmovibleXML->FirstChildElement("Y")->GetText ());
		std::string id = manejadorIDs.getIDInmovible ();
		Inmovible* inmovible = fabricaInmovibles->getInmovible (tipo,x,y,id);
		inmovibles[id] = inmovible;
		Mensaje mensajeInmovible;
		mensajeInmovible.mensajeDeCrear (inmovible,id, SIN_EQUIPO);
		this->enviarMensaje (mensajeInmovible);
		inmovibleXML = inmovibleXML->NextSiblingElement (nombreObjetos.c_str());
	}
}

void Juego::enviarMensaje(Mensaje& mensaje) {
	for (Jugador *jugador: jugadores) {
		std::string mensajeStr = mensaje.getMensaje();
		try {
			jugador->enviarMensaje (mensajeStr, mensaje.getId ());		
		} catch (SocketException &e) {
			std::cout<<"Se desconectará el servidor"<<std::endl;
			this->finalizar (); 
		}
	}
}

Juego::Juego (ColaMensajes& colaDeRecibidos, std::vector<Jugador*>& jugadores) :	
												colaDeRecibidos(colaDeRecibidos),
												mapa(Mapa("mapa.map")), 
												jugadores(jugadores),
												fabricaUnidades(new FabricaUnidades()),
												fabricaMuniciones(new FabricaMuniciones()),
												fabricaEdificios(new FabricaEdificios()),
												fabricaInmovibles(new FabricaInmovibles())
												 { 
  
	
	finalizado.set_value (false);  
	int equipo = equipo_1;
	for (Jugador *jugador: jugadores) {
		jugador->setEquipo (equipo%NUM_EQUIPOS); 
		Mensaje mensaje;
		mensaje.mensajeDeEquipo(jugador);
		std::string mensajeStr = mensaje.getMensaje ();
		jugador->enviarMensaje (mensajeStr,mensaje.getId ()); //Envio equipo		
		++equipo;
	}
  
	Mensaje mensajeMapa;
	mensajeMapa.mensajeDeMapa (mapa);
	this->enviarMensaje (mensajeMapa);

	banderasPorEquipo = {1,1,1,1}; //Lleva noción de territorios

	this->inicializarJuego ("configuracion.xml");
	
}

void Juego::inicializarJuego(const std::string& nombreArchivo) {
	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile(nombreArchivo.c_str())) {
 		xml.PrintError ();
 		return ;
 	}

	tinyxml2::XMLElement* config = xml.FirstChildElement ("CONFIGURACION");	
	this->inicializarEdificios (3,config,"FUERTES");
	this->inicializarEdificios (4,config,"FABRICAS_ROBOTS");
	this->inicializarEdificios (5,config,"FABRICAS_VEHICULOS");
	this->inicializarInmovibles (2,config,"BANDERAS","BANDERA");
	this->inicializarInmovibles (0,config,"ROCAS","ROCA");
}

void Juego::eliminarMuertos() {

	std::map<std::string, Movible*>::iterator it1 = movibles.begin ();

	while (it1!=movibles.end()) {
		Movible* movible = it1->second;
		if (!movible->estaVivo ()) {
			Mensaje mensajeMatar;
			mensajeMatar.mensajeDeMatar (it1->first);
			colaDeEnviados.encolar (mensajeMatar);
			it1 = movibles.erase (it1);
			delete movible;
			continue;
		}
		++it1;
	}
	std::map<std::string,Inmovible*>::iterator it2 = inmovibles.begin ();
	while (it2!=inmovibles.end()) {
		Inmovible* inmovible = it2->second;
		if (!inmovible->estaVivo()) {
			Mensaje mensajeMatar;
			mensajeMatar.mensajeDeMatar (it2->first);
			colaDeEnviados.encolar (mensajeMatar);
			it2 = inmovibles.erase (it2);
			delete inmovible;
			continue;
		}
		++it2;
	}
	std::map<std::string,Edificio*>::iterator it3 = edificios.begin ();
	while (it3!=edificios.end()) {
		Edificio* edificio = it3->second;
		if (!edificio->estaVivo()) {
			Mensaje mensajeMatar;
			mensajeMatar.mensajeDeMatar (it3->first);
			colaDeEnviados.encolar (mensajeMatar);
			it3 = edificios.erase (it3);
			delete edificio;
			continue;
		}
		++it3;
	}
	
}

void Juego::moverUnidades() {
	std::map<std::string, Movible*>::iterator it1 = movibles.begin ();
	
	while (it1 != movibles.end()) {
		Movible* movible = it1->second;
		std::array<double,2> pos = movible->getPosicion ();
		std::array<int,2> posCasillero = {(int) pos[0], (int) pos[1]};
		double factorTerreno = mapa.obtenerFactorTerreno (posCasillero, movible);
		if (movible->mover (factorTerreno)) {
			Mensaje mensajeMover;
			mensajeMover.mensajeDeMover (movible, it1->first);
			colaDeEnviados.encolar (mensajeMover);
		}
		++it1;
	}
}

void Juego::chequearColisiones () {
	//Chequeo con objetos movibles
	std::map<std::string, Movible*>::iterator it1 = movibles.begin ();
	
	while (it1 != movibles.end()) {
		Movible* mov1 = (it1)->second;
		std::map<std::string,Inmovible*>::iterator it2 = inmovibles.begin ();
		while (it2 != inmovibles.end()) {
			Inmovible* inMov2 = (it2)->second;
			if (mov1->colisiona(*inMov2)) {
				inMov2->colisionar (*mov1);
				mov1->colisionar(*inMov2);
			}
			++it2;
		}
		std::map<std::string, Movible*>::iterator it3 = movibles.begin ();
		while (it3 != movibles.end()) {
			if (it1 == it3) {
				++it3;
				continue;	//No comparo con si mismo	
			}
			Movible* mov2 = (it3)->second;
			if (mov1->colisiona(*mov2)) {
				mov1->colisionar(*mov2);
			}
			++it3;
		}
		std::map<std::string, Edificio*>::iterator it4 = edificios.begin ();
		while (it4 != edificios.end()) {
			Edificio* edificio = (it4)->second;
			if (mov1->colisiona(*edificio)) {
				mov1->colisionar(*edificio);
				edificio->colisionar(*mov1);
			}
			++it4;
		}
		if (mov1->obtuvoBandera ()) {
			std::string idBandera = ((Unidad*) mov1)->getBandera ();
			Mensaje mensajeBorrar;
			mensajeBorrar.mensajeDeMatar (idBandera);
			colaDeEnviados.encolar (mensajeBorrar);
			Mensaje mensajeCrear;
			Bandera* bandera = (Bandera*) inmovibles[idBandera];
			mensajeCrear.mensajeDeCrear (bandera,idBandera,bandera->getEquipo ());
			colaDeEnviados.encolar (mensajeCrear);
			banderasPorEquipo[mov1->getEquipo ()] ++;
		}
		++it1;
	}
}

void Juego::actualizarDisparos() {
	std::map<std::string, Movible*>::iterator it1 = movibles.begin ();
	
	while (it1 != movibles.end()) {
		Movible* movible = (it1)->second;
		std::string idObjetivo = movible->puedeDisparar ();
		if (idObjetivo.empty ()) {
			++it1;
			continue;
		}
		Objeto* objetivo;
		if (movibles.count (idObjetivo)) {
			objetivo = movibles[idObjetivo];
		} else if (inmovibles.count(idObjetivo)) {
			objetivo = inmovibles[idObjetivo];
		} else {
			movible->setObjetivo(std::string());
			++it1;
			continue;
		}
		
		double alcance = fabricaUnidades->getAlcance (movible->getTipo ());
		if (movible->distanciaCuadrada (objetivo)>alcance*alcance) {
			movible->setObjetivo(std::string());
			++it1;
			continue;
		}
		
		//Si tiene el movible puede disparar entonces es una unidad
		int armamento = ((Unidad*) movible)->getArmamento ();
		std::cout<<"antes de fabrica municiones"<<std::endl;
		Municion* municion = fabricaMuniciones->getMunicion (armamento);
		municion->setEquipo (movible->getEquipo ());
		municion->setPosicion (movible->getPosicion ());
		municion->setObjetivo (idObjetivo);
		municion->setAlcance (alcance);
		std::array<double,2> target = objetivo->getPosicion ();
		municion->mover (target);
		std::string idMunicion = manejadorIDs.getIDMunicion ();
		movibles[idMunicion] = municion;

		//Envio mensaje de disparo
		Mensaje mensajeDisparar;
		mensajeDisparar.mensajeDeDisparar (it1->first, objetivo);
		colaDeEnviados.encolar (mensajeDisparar);

		//Envio mensaje crear municion
		Mensaje mensajeCrear;
		mensajeCrear.mensajeDeCrear (municion,idMunicion,
									 municion->getEquipo ());
		colaDeEnviados.encolar (mensajeCrear);

		++it1;
	}
}

void Juego::actualizarEdificios() {
	std::map<std::string, Edificio*>::iterator it = edificios.begin ();
	while (it != edificios.end()) {
		std::string clave = (it)->first;
		Edificio* edificio = (it)->second;
		std::array<double,2> posEdificio = edificio->getPosicion ();
		int tipo = edificio->debeCrear();

		if (tipo == -1) {
			++it;
			continue;
		}
		Unidad* unidad = fabricaUnidades->getUnidad (tipo);
		std::string id = manejadorIDs.getIDMovible ();
		unidad->setId (id);
		unidad->setEquipo (edificio->getEquipo ());
		movibles[id] = unidad;
		//Posicion de creacion hardcodeada
		//Todos se crean en la misma posicion
		//TODO
		unidad->setPosicion ({posEdificio[0]-2,posEdificio[1]-2});
		Mensaje mensajeCrear;
		mensajeCrear.mensajeDeCrear (unidad,id,unidad->getEquipo ());
		colaDeEnviados.encolar (mensajeCrear);
		++it;
	}
}

void Juego::actualizarRecibidos() {
	while (!colaDeRecibidos.isEmpty ()) {
		Mensaje paquete = colaDeRecibidos.desencolar ();
		std::string mensaje = paquete.getMensaje ();
		int src = paquete.getId ();
		switch (mensaje[0]) {
			case comandoCrear:			this->recibirCrear (mensaje);
										break;
			case comandoMover:			this->recibirMover(mensaje);
										break;
			case comandoDisparar:		this->recibirDisparar(mensaje);
										break;
			case comandoInfo:			this->recibirObtenerInfo(mensaje, src);
										break;
			case comandoDesconectar:	this->finalizar();
										break;
		}		
	}
}

void Juego::recibirCrear(std::string mensaje) {
	std::string idStr = mensaje.substr(1, largoId);
	std::string tipoStr = mensaje.substr (4, largoTipo);
	
	int tipo = stoi(tipoStr);
	int tiempo;
	if (tipo>=6 && tipo<=10) {
		tiempo = fabricaUnidades->getTiempo (tipo);
	} else if (tipo>=11 && tipo<=16) {
		tiempo = fabricaUnidades->getTiempo (tipo);
	}
	Edificio* edificio = edificios[idStr];
	int equipo = edificio->getEquipo ();
	int cantTerritorios = banderasPorEquipo[equipo];
	edificio->setFabricacion (tiempo,cantTerritorios,tipo);
}

void Juego::recibirMover(std::string mensaje) {
	std::string idStr = mensaje.substr(1,largoId);
	std::string xStr = mensaje.substr(4,largoX);
	std::cout<<xStr<<std::endl;
	std::string yStr = mensaje.substr(9,largoY);
	std::cout<<yStr<<std::endl;

	double x = stod(xStr,NULL)/100;
	double y = stod(yStr,NULL)/100;
	
	std::array<double,2> inicio = movibles[idStr]->getPosicion ();
	AEstrella aEstrella(mapa);
	std::vector< std::array<double,2> > recorrido = 
								aEstrella.getRecorrido (movibles[idStr],
														{inicio[0],inicio[1]},
														{(int) x,(int) y});
	movibles[idStr]->setTrayectoria(recorrido);
}

void Juego::recibirDisparar(std::string mensaje) {
	std::string idAgresor = mensaje.substr(1,largoId);
	std::string idAgredido = mensaje.substr(4, largoId);
	((Unidad*) movibles[idAgresor])->dispararA (idAgredido);
}

void Juego::recibirObtenerInfo (std::string mensaje, int src) {
	std::string idStr = mensaje.substr(1,largoId);
	if (movibles.count(idStr)) {
		this->enviarInfoUnidad(idStr,src);
	} else if (edificios.count(idStr)) {
		this->enviarInfoFabrica(idStr,src);
	}
}

void Juego::enviarInfoUnidad (std::string id, int dst) {
	Movible* movible = movibles[id];
	Mensaje mensajeInfoUnidad;
	mensajeInfoUnidad.mensajeDeInfoUnidad((Unidad*) movible, id, dst);
	colaDeEnviados.encolar (mensajeInfoUnidad);
}

void Juego::enviarInfoFabrica (std::string id, int dst) {
	Edificio* edificio = edificios[id];
	Mensaje mensajeInfoFabrica;
	mensajeInfoFabrica.mensajeDeInfoFabrica (edificio,id,fabricaUnidades,dst);
	colaDeEnviados.encolar (mensajeInfoFabrica);
}

void Juego::enviarMensajesEncolados() {
	while (!colaDeEnviados.isEmpty ()) {
		std::cout<<colaDeEnviados.size()<<std::endl;
		Mensaje mensaje = colaDeEnviados.desencolar ();
		this->enviarMensaje (mensaje);
	}
}

void Juego::run() {
	while (!this->yaFinalizo()) {
		clock_t tiempo1 = clock();
		std::cout<<"actualizarRecibidos"<<std::endl;
		this->actualizarRecibidos ();
		std::cout<<"actualizarEdificios"<<std::endl;
		this->actualizarEdificios();
		std::cout<<"actualizarDisparos"<<std::endl;
		this->actualizarDisparos();
		std::cout<<"moverUnidades"<<std::endl;
		this->moverUnidades ();
		std::cout<<"chequearColisiones"<<std::endl;
		this->chequearColisiones();
		std::cout<<"eliminarMuertos"<<std::endl;
		this->eliminarMuertos();
		std::cout<<"enviarMensajesEncolados"<<std::endl;
		this->enviarMensajesEncolados();
		if (this->hayGanador ()) {
			this->finalizar();
		}
		clock_t tiempo2 = clock();
		double intervaloDormir = CYCLE_TIME - 
									double(tiempo2 - tiempo1)/CLOCKS_PER_SEC;
		while (intervaloDormir<0) {
			intervaloDormir+=CYCLE_TIME;
		}
		struct timespec req = {0};
		req.tv_sec = 0;
		req.tv_nsec = intervaloDormir*NANO;
		while (nanosleep(&req, &req) == -1); 
	}
	
	for (Jugador* jugador : jugadores) {
		jugador->finalizar();
	}
}

bool Juego::hayGanador() {
	return false;
}

bool Juego::yaFinalizo () {
	return finalizado.get_value ();
}

void Juego::finalizar() {
	finalizado.set_value (true);
}

Juego::~Juego () { 
	//Limpiar movibles, porque son punteros
	//Limpiar inmovibles, porque son punteros
}
