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
#include <tinyxml2.h>

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

Juego::Juego (ColaMensajes& colaDeRecibidos, std::vector<Jugador*>& jugadores) :	
												colaDeRecibidos(colaDeRecibidos),
												mapa(Mapa("mapa.map")), 
												proximoIDMovible(0),
												jugadores(jugadores),
												fabricaUnidades(new FabricaUnidades()),
												fabricaMuniciones(new FabricaMuniciones())
												 { 
  
	
	finalizado.set_value (false);  
	
	for (Jugador *jugador: jugadores) {
		jugador->setEquipo (equipo_1);
		Mensaje mensaje;
		mensaje.mensajeDeEquipo(jugador);
		std::string mensajeStr = mensaje.getMensaje ();
		jugador->enviarMensaje (mensajeStr,mensaje.getId ()); //Envio equipo		
	}
  
	Mensaje mensajeMapa;
	mensajeMapa.mensajeDeMapa (mapa);
	for (Jugador *jugador: jugadores) {
		std::string mensajeStr = mensajeMapa.getMensaje();
		jugador->enviarMensaje (mensajeStr, mensajeMapa.getId ()); //Envio mapa		
	}

	banderasPorEquipo = {1,1,1,1}; //Lleva noción de territorios
	
	proximoIDMovible = 0;

	//TODO inicializar juego (no hardcodeado)

	this->inicializarJuego ("configuracion.xml");
	
/*	Bandera* bandera = new Bandera(2,1.5,2);
	bandera->setPosicion ({0,0});
	bandera->setEquipo(0);
	inmovibles["i00"] = bandera;
	
	Mensaje mensajeBandera;
	// TODO reemplazar id hardcodeado
	mensajeBandera.mensajeDeCrear (bandera,std::string("i00"),bandera->getEquipo ());
	for (Jugador *jugador : jugadores) {
		std::string mensajeStr = mensajeBandera.getMensaje ();
		jugador->enviarMensaje (mensajeStr, mensajeBandera.getId ());		
	}
	
	Robot* robot = fabricaUnidades->getRobot (9);
	movibles["m00"] = (robot);
	robot->setPosicion ({2,0});
	robot->setEquipo (0);
	
	Mensaje mensajeRobot;
	// TODO reemplazar id hardcodeado
	mensajeRobot.mensajeDeCrear (robot,std::string("m00"), robot->getEquipo ());
	for (Jugador *jugador : jugadores) {
		std::string mensajeStr = mensajeRobot.getMensaje ();
		jugador->enviarMensaje (mensajeStr, mensajeRobot.getId ());		
	}

	proximoIDMovible++;
	
	Bloque* bloque = new Bloque(10,2,2,0);
	inmovibles["i01"] = (bloque);
	bloque->setPosicion ({4,4});
	
	Mensaje mensajeBloque;
	// TODO reemplazar SIN_EQUIPO
	// TODO reemplazar id hardcodeado
	mensajeBloque.mensajeDeCrear (bloque,std::string("i01"), SIN_EQUIPO);
	for (Jugador *jugador : jugadores) {
		std::string mensajeStr = mensajeBloque.getMensaje ();
		jugador->enviarMensaje (mensajeStr, mensajeBloque.getId ());		
	}

	Edificio* edificio = new Edificio(10,10,12,0,3);
	edificios["i02"] = (edificio);
	edificio->setPosicion ({10,3});
	edificio->setEquipo(0);
	
	Mensaje mensajeEdificio;
	// TODO reemplzar id hardcodeado
	mensajeEdificio.mensajeDeCrear (edificio,std::string("i02"), edificio->getEquipo ());
	for (Jugador *jugador : jugadores) {
		std::string mensajeStr = mensajeEdificio.getMensaje ();
		jugador->enviarMensaje (mensajeStr, mensajeBloque.getId());		
	}*/
}

void Juego::inicializarJuego(const std::string& nombreArchivo) {
	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile(nombreArchivo.c_str())) {
 		xml.PrintError ();
 		return ;
 	}
	
	tinyxml2::XMLElement* config = xml.FirstChildElement ("CONFIGURACION");
	tinyxml2::XMLElement* fuertes = config->FirstChildElement ("FUERTES");
	//TODO reemplazar 4 hardcodeado
	//TODO reemplazar parametros de edificios hardcodeados, fabricaEdificios
	tinyxml2::XMLElement* fuerte = fuertes->FirstChildElement ("FUERTE");
	for (int i = 0; i < jugadores.size () && i < 4; ++i) {
		int equipo = atoi(fuerte->FirstChildElement("EQUIPO")->GetText ());
		int x = atoi(fuerte->FirstChildElement("X")->GetText ());
		int y = atoi(fuerte->FirstChildElement("Y")->GetText ());
		Edificio* edificio = new Edificio(10,x,y,equipo,3);
		std::string id = std::string("i") + agregarPadding(proximoIDInmovible,2);
		edificios[id] = edificio;
		proximoIDInmovible++;
		edificio->setPosicion ({x,y});
		edificio->setEquipo(equipo);

		Mensaje mensajeEdificio;
		mensajeEdificio.mensajeDeCrear (edificio,id, edificio->getEquipo ());
		for (Jugador *jugador : jugadores) {
			std::string mensajeStr = mensajeEdificio.getMensaje ();
			jugador->enviarMensaje (mensajeStr, mensajeEdificio.getId());
		}
		fuerte = fuerte->NextSiblingElement ("FUERTE");
	}
	
	
	
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
			std::string idMunicion = "m"+agregarPadding(proximoIDMovible,2);
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
			
			proximoIDMovible ++;
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
	std::string yStr = mensaje.substr(10,y);
	
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
		for (Jugador *jugador : jugadores) {
			std::string mensajeStr = mensaje.getMensaje ();
			try {
				jugador->enviarMensaje (mensajeStr, mensaje.getId ());		
			} catch (SocketException &e) {
				std::cout<<"Se desconectará el servidor"<<std::endl;
				this->finalizar ();
			}	
		}
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
