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

#define SIN_EQUIPO 4

enum equipos {
	equipo_1,
	equipo_2,
	equipo_3,
	equipo_4
};

enum comandos {
	crear = '0',
	matar = '1',
	mover = '2',
	disparar = '3',
	info = '4',
	infoUnidad = '4',
	mapa = '5',
	equipo = '6',
	infoFabrica = '7',
	desconectar = '8'
};

enum largos {
	comando = 1,
	id = 3,
	x = 5,
	y = 5,
	delCliente = 1,
	tipo = 2,
	color = 1
};

std::string agregarPadding(int n, int len) {
	std::string nStr = std::to_string(n);
	int lenN = nStr.size();
	for (int i=0;i<(len-lenN);i++) {
		nStr.insert (0,"0");
	}  
	return nStr;
}

void Juego::inicializarEdificios(int tipo, tinyxml2::XMLElement* padre, 
									std::string nombreXML) {
	
	tinyxml2::XMLElement* edificiosXML = padre->FirstChildElement (nombreXML.c_str());
	tinyxml2::XMLElement* edificioXML = edificiosXML->FirstChildElement ("EDIFICIO");
	for (int i = 0; i < jugadores.size () && i < 4; ++i) {
		int equipo = atoi(edificioXML->FirstChildElement("EQUIPO")->GetText ());
		double x = atof(edificioXML->FirstChildElement("X")->GetText ());
		double y = atof(edificioXML->FirstChildElement("Y")->GetText ());
		std::string id = std::string("i") + agregarPadding(proximoIDInmovible,2);
		proximoIDInmovible++;		
		Edificio* edificio = fabricaEdificios->getEdificio (tipo,equipo,x,y,id);
		edificios[id] = edificio;
		
		Mensaje mensajeEdificio;
		mensajeEdificio.mensajeDeCrear (edificio,id, edificio->getEquipo ());
		this->enviarMensaje(mensajeEdificio);
		edificioXML = edificioXML->NextSiblingElement ("EDIFICIO");
	}
}

void Juego::inicializarBanderas(int tipo, tinyxml2::XMLElement* padre, 
								std::string nombreXML) {
  	tinyxml2::XMLElement* banderas = padre->FirstChildElement (nombreXML.c_str ());
	//TODO reemplazar 4 hardcodeado
	//TODO reemplazar parametros de edificios hardcodeados, fabricaEdificios
	tinyxml2::XMLElement* banderaXML = banderas->FirstChildElement ("BANDERA");
	for (int i = 0; banderaXML != NULL; ++i) {
		int x = atoi(banderaXML->FirstChildElement("X")->GetText ());
		int y = atoi(banderaXML->FirstChildElement("Y")->GetText ());
		Bandera* bandera = new Bandera(2,1.5,tipo);
		std::string id = std::string("i") + agregarPadding(proximoIDInmovible,2);
		bandera->setId (id);
		inmovibles[id] = bandera;
		proximoIDInmovible++;
		bandera->setPosicion ({x,y});
		bandera->setEquipo(SIN_EQUIPO);

		Mensaje mensajeBandera;
		mensajeBandera.mensajeDeCrear (bandera,id, bandera->getEquipo ());
		this->enviarMensaje (mensajeBandera);
		banderaXML = banderaXML->NextSiblingElement ("BANDERA");
	}

}

void Juego::inicializarRocas(int tipo, tinyxml2::XMLElement* padre,
								std::string nombreXML) {
	tinyxml2::XMLElement* rocas = padre->FirstChildElement (nombreXML.c_str ());
	//TODO reemplazar 4 hardcodeado
	//TODO reemplazar parametros de bloques hardcodeados, fabricaEdificios
	tinyxml2::XMLElement* roca = rocas->FirstChildElement ("ROCA");
	for (int i = 0; roca != NULL; ++i) {
		int x = atoi(roca->FirstChildElement("X")->GetText ());
		int y = atoi(roca->FirstChildElement("Y")->GetText ());
		Bloque* bloque = new Bloque(10,2,2,tipo);
		std::string id = std::string("i") + agregarPadding(proximoIDInmovible,2);
		bloque->setId (id);
		inmovibles[id] = bloque;
		proximoIDInmovible++;
		bloque->setPosicion ({x,y});

		Mensaje mensajeRoca;
		mensajeRoca.mensajeDeCrear (bloque,id, SIN_EQUIPO);
		this->enviarMensaje (mensajeRoca);
		roca = roca->NextSiblingElement ("ROCA");
	}  
}

void Juego::enviarMensaje(Mensaje& mensaje) {
	for (Jugador *jugador: jugadores) {
		std::string mensajeStr = mensaje.getMensaje();
		jugador->enviarMensaje (mensajeStr, mensaje.getId ());		
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
												proximoIDMovible(0),
												proximoIDInmovible(0),
												proximoIDBala(0),
												jugadores(jugadores),
												fabricaUnidades(new FabricaUnidades()),
												fabricaMuniciones(new FabricaMuniciones()),
												fabricaEdificios(new FabricaEdificios())
												 { 
  
	
	finalizado.set_value (false);  
	int i = 0;
	for (Jugador *jugador: jugadores) {
		//TODO emprolijar asignacion de equipos
		jugador->setEquipo (i%4); 
		Mensaje mensaje;
		mensaje.mensajeDeEquipo(jugador);
		std::string mensajeStr = mensaje.getMensaje ();
		jugador->enviarMensaje (mensajeStr,mensaje.getId ()); //Envio equipo		
		++i;
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
	this->inicializarBanderas (2,config,"BANDERAS");
	this->inicializarRocas (0,config,"ROCAS");
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
		  
		if (objetivo) {
			//Si tiene el movible puede disparar entonces es una unidad
			int armamento = ((Unidad*) movible)->getArmamento ();
			std::cout<<"antes de fabrica municiones"<<std::endl;
			Municion* municion = fabricaMuniciones->getMunicion (armamento);
			//TODO siempre busca en fabrica de robots, verificar para vehiculos tambien
			double alcance = fabricaUnidades->getAlcance (movible->getTipo ());
			municion->setEquipo (movible->getEquipo ());
			municion->setPosicion (movible->getPosicion ());
			municion->setObjetivo (idObjetivo);
			municion->setAlcance (alcance);
			std::array<double,2> target = objetivo->getPosicion ();
			municion->mover (target);
			std::string idMunicion = agregarPadding(proximoIDBala,3);
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
			
			proximoIDBala ++;
		}
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
		if (tipo>=11 && tipo<=16) {
			Vehiculo* vehiculo = fabricaUnidades->getVehiculo (tipo);
			std::string id ="m"+agregarPadding(proximoIDMovible,2);
			movibles[id] = vehiculo;
			vehiculo->setEquipo (edificio->getEquipo ());
			//Posicion de creacion hardcodeada
			//Todos se crean en la misma posicion
			//TODO
			vehiculo->setPosicion ({posEdificio[0]-2,posEdificio[1]-2});
			Mensaje mensajeCrear;
			mensajeCrear.mensajeDeCrear (vehiculo,id,vehiculo->getEquipo ());
			colaDeEnviados.encolar (mensajeCrear);
			
			std::cout<<"creo vehiculo"<<std::endl;
			proximoIDMovible++;
		}
		if (tipo>=6 && tipo<=10) {
			Robot* robot = fabricaUnidades->getRobot (tipo);
			std::string id ="m"+agregarPadding(proximoIDMovible,2);
			movibles[id] = robot;
			robot->setEquipo (edificio->getEquipo ());
			//Posicion de creacion hardcodeada
			//Todos se crean en la misma posicion
			//TODO
			robot->setPosicion ({posEdificio[0]-2,posEdificio[1]-2});
			Mensaje mensajeCrear;
			mensajeCrear.mensajeDeCrear (robot,id,robot->getEquipo ());
			colaDeEnviados.encolar (mensajeCrear);
			
			std::cout<<"creo robot"<<std::endl;
			proximoIDMovible++;
		}
		++it;
	}
}

void Juego::actualizarRecibidos() {
	while (!colaDeRecibidos.isEmpty ()) {
		Mensaje paquete = colaDeRecibidos.desencolar ();
		std::string mensaje = paquete.getMensaje ();
		int src = paquete.getId ();
		switch (mensaje[0]) {
			case crear: this->recibirCrear (mensaje);
						break;
			case mover: this->recibirMover(mensaje);
						break;
			case disparar: this->recibirDisparar(mensaje);
						break;
			case info: 
						if (mensaje[1] == 'm')
							this->recibirObtenerInfoUnidad(mensaje, src);
						if (mensaje[1] == 'i')
							this->recibirObtenerInfoFabrica(mensaje, src);
						break;
		  case desconectar: 
						this->finalizar();
						break;
		}		
	}
}

void Juego::recibirCrear(std::string mensaje) {
	std::string idStr = mensaje.substr(1,id);
	std::string tipoStr = mensaje.substr (4,tipo);
	
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
	std::string idStr = mensaje.substr(1,id);
	std::string xStr = mensaje.substr(4,x);
	std::cout<<xStr<<std::endl;
	std::string yStr = mensaje.substr(9,y);
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
	std::string idAgresor = mensaje.substr(1,id);
	std::string idAgredido = mensaje.substr(4,id);
	((Unidad*) movibles[idAgresor])->dispararA (idAgredido);
}

void Juego::recibirObtenerInfoUnidad (std::string mensaje, int src) {
	std::string idStr = mensaje.substr(1,id);
	this->enviarInfoUnidad (idStr, src);
}

void Juego::recibirObtenerInfoFabrica (std::string mensaje, int src) {
	std::string idStr = mensaje.substr(1,id);
	this->enviarInfoFabrica (idStr, src);
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
		Mensaje mensaje = colaDeEnviados.desencolar ();
		this->enviarMensaje (mensaje);
	}
}

void Juego::run() {
	while (!this->yaFinalizo()) {
		clock_t tiempo1 = clock();
		this->actualizarRecibidos ();
		this->actualizarEdificios();
		this->actualizarDisparos();
		this->moverUnidades ();
		this->chequearColisiones();
		this->eliminarMuertos();
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
