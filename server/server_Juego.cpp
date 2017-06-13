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
#include <chrono>
#include <string>

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
	infoFabrica = '7'
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

Juego::Juego (std::queue<std::string>* colaDeRecibidos, std::mutex* m, 
			  std::condition_variable* cond, Socket* socket) :	
								colaDeRecibidos(colaDeRecibidos),
												m(m),		
												cond(cond),
												mapa(Mapa("mapa.map")), 
												proximoIDMovible(0),
												socket(socket){ 

	std::string mensaje = "6" + std::to_string(equipo_1);
	socket->SendStrWLen (mensaje); //Envio equipo
  
	std::string mapaString = mapa.obtenerMensajeMapa ();
	mensaje = "5" + mapaString; //No se envia el tamaño porque es convención	
	std::cout << mensaje.substr(0,1) << std::endl;
	socket->SendStrWLen (mensaje); //Envio mapa
	
			
	banderasPorEquipo = {1,1,1,1}; //Lleva noción de territorios
	
	proximoIDMovible = 0;
	
	Bandera* bandera = new Bandera(2,1.5,2);
	bandera->setPosicion ({0,0});
	bandera->setEquipo(0);
	inmovibles["i00"] = bandera;
	
	int mensajeX = bandera->getPosicion ()[0]*100;
	std::string xStr = agregarPadding(mensajeX,5);

	int mensajeY = bandera->getPosicion ()[1]*100;
	std::string yStr = agregarPadding(mensajeY,5);

	std::string tipo = agregarPadding(bandera->getTipo (),2);
	std::string comando = "0i00";

	mensaje = comando+xStr+yStr+tipo+std::to_string(bandera->getEquipo ());	
	socket->SendStrWLen (mensaje);
	
	FabricaRobots* fabricaR = FabricaRobots::getInstancia ();
	Robot* robot = fabricaR->getRobot (9);
	movibles["m00"] = (robot);
	robot->setPosicion ({2,0});
	robot->setEquipo (0);
	
	xStr = agregarPadding(2*100,5);
	yStr = agregarPadding(0*100,5);
	tipo = agregarPadding(robot->getTipo (),2);
	comando = "0m00";
	mensaje = comando+xStr+yStr+tipo+std::to_string(robot->getEquipo ());	
	socket->SendStrWLen (mensaje);

	proximoIDMovible++;
	
	Bloque* bloque = new Bloque(10,2,2,0);
	inmovibles["i01"] = (bloque);

	bloque->setPosicion ({4,4});

	xStr = agregarPadding(4*100,5);
	yStr = agregarPadding(4*100,5);
	tipo = agregarPadding(bloque->getTipo (),2);
	comando = "0i01";
	mensaje = comando+xStr+yStr+tipo+std::string("0");	
	socket->SendStrWLen (mensaje);

	//    Edificio(int vida, double ancho, double alto, int idEquipo, int tipo);
	Edificio* edificio = new Edificio(10,10,12,0,3);
	edificios["i02"] = (edificio);

	bloque->setPosicion ({10,3});

	xStr = agregarPadding(10*100,5);
	yStr = agregarPadding(3*100,5);
	tipo = agregarPadding(edificio->getTipo (),2);
	comando = "0i02";
	mensaje = comando+xStr+yStr+tipo+std::string("0");	
	socket->SendStrWLen (mensaje);
	
}

void Juego::eliminarMuertos() {

	std::map<std::string, Movible*>::iterator it1 = movibles.begin ();

	while (it1!=movibles.end()) {
		Movible* movible = it1->second;
		if (!movible->estaVivo () || movible->superaMaxDistancia ()) {
//			std::cout<<"Id: "<<it1->first<<std::endl;
//			std::cout<<"Vida: "<<movible->getVida ()<<std::endl;
//			std::cout<<"elimino un movible"<<std::endl;
			std::string mensaje = "1"+it1->first;
			colaDeEnviados.push(mensaje);
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
			std::cout<<"elimino un inmovible"<<std::endl;
			std::string mensaje = "1"+it2->first;
			colaDeEnviados.push(mensaje);
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
			std::cout<<"elimino un edificio"<<std::endl;
			std::string mensaje = "1"+it3->first;
			colaDeEnviados.push(mensaje);
			it3 = edificios.erase (it3);
			delete edificio;
			continue;
		}
		++it3;
	}
	
}

void Juego::moverUnidades() {
	std::map<std::string, Movible*>::iterator it1 = movibles.begin ();
	
	//for (Movible* movible: movibles) {
	while (it1 != movibles.end()) {
		Movible* movible = it1->second;
		std::array<double,2> pos = movible->getPosicion ();
		std::array<int,2> posCasillero = {(int) pos[0], (int) pos[1]};
//		std::cout<<"casillero: "<<posCasillero[0]<<","<<posCasillero[1]<<std::endl;
		double factorTerreno = mapa.obtenerFactorTerreno (posCasillero);
//		std::cout<<"Factor de terreno "<<factorTerreno<<std::endl;
		//Siempre devuelve el factor terreno de robot (agregar 2xDispatch)
		//TODO
		if (movible->mover (factorTerreno)) {
			pos = movible->getPosicion ();
//			std::cout<<"pos: "<<pos[0]<<","<<pos[1]<<std::endl;
			int mensajeX = pos[0]*100;
			std::string xStr = agregarPadding(mensajeX,5);

			int mensajeY = pos[1]*100;
			std::string yStr = agregarPadding(mensajeY,5);
			
			std::string mensaje = "2"+it1->first+xStr+yStr;
			colaDeEnviados.push (mensaje);
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
				std::cout<<it1->first<<" colision con "<<it3->first<<std::endl;
//				std::cout<<"Antes "<<mov1->getVida ()<<std::endl;
				mov1->colisionar(*mov2);
//				std::cout<<"Despues " << mov1->getVida ()<<std::endl;
			}
			++it3;
		}
		std::map<std::string, Edificio*>::iterator it4 = edificios.begin ();
		while (it4 != edificios.end()) {
			Edificio* edificio = (it4)->second;
			if (mov1->colisiona(*edificio)) {
				mov1->colisionar(*edificio);
				edificio->colisiona (*mov1);
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
	FabricaMuniciones* fabricaMuniciones = FabricaMuniciones::getInstancia();
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
			Municion* municion = fabricaMuniciones->getMunicion (17);
			municion->setEquipo (movible->getEquipo ());
			municion->setPosicion (movible->getPosicion ());
			municion->setObjetivo (idObjetivo);
			std::array<double,2> target = objetivo->getPosicion ();
			municion->mover (target);
			movibles["m"+agregarPadding(proximoIDMovible,2)] = municion;
			int mensajeX = target[0]*100;
			std::string xStr = agregarPadding(mensajeX,5);
			int mensajeY = target[1]*100;
			std::string yStr = agregarPadding(mensajeX,5);
			std::string mensaje = "3"+it1->first+xStr+yStr;
			std::cout<<mensaje<<std::endl;
			proximoIDMovible ++;
		}
		++it1;
	}
}

void Juego::actualizarEdificios() {
	FabricaRobots* fabricaR = FabricaRobots::getInstancia ();
	FabricaVehiculos* fabricaV = FabricaVehiculos::getInstancia ();
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
		if (tipo>=6 && tipo<=10) {
			Vehiculo* vehiculo = fabricaV->getVehiculo (tipo);
			std::string id ="m"+agregarPadding(proximoIDMovible,2);
			movibles[id] = vehiculo;
			//Posicion de creacion hardcodeada
			//Todos se crean en la misma posicion
			//TODO
			vehiculo->setPosicion ({posEdificio[0]+1,posEdificio[1]+1});
			int mensajeX = vehiculo->getPosicion ()[0]*100;
			std::string xStr = agregarPadding(mensajeX,5);
			int mensajeY = vehiculo->getPosicion ()[1]*100;
			std::string yStr = agregarPadding(mensajeY,5);
			std::string tipo = agregarPadding(vehiculo->getTipo (),2);
			std::string mensaje = "0"+id+xStr+yStr+tipo+std::to_string(vehiculo->getEquipo ());
			//Avisar al cliente que se creo un vehiculo
			colaDeEnviados.push (mensaje);
			
			std::cout<<"creo edificio"<<std::endl;
			proximoIDMovible++;
		}
		if (tipo>=11 && tipo<=16) {
			Robot* robot = fabricaR->getRobot (tipo);
			movibles["m"+agregarPadding(proximoIDMovible,2)] = robot;
			
			//Posicion de creacion hardcodeada
			//Todos se crean en la misma posicion
			//TODO
			robot->setPosicion ({posEdificio[0]+1,posEdificio[1]+1});
			int mensajeX = robot->getPosicion ()[0]*100;
			std::string xStr = agregarPadding(mensajeX,5);
			int mensajeY = robot->getPosicion ()[1]*100;
			std::string yStr = agregarPadding(mensajeY,5);
			std::string tipo = agregarPadding(robot->getTipo (),2);
			std::string mensaje = "0"+id+xStr+yStr+tipo+std::to_string(robot->getEquipo ());
			//Avisar al cliente que se creo un vehiculo
			colaDeEnviados.push (mensaje);

			std::cout<<"creo robot"<<std::endl;
			proximoIDMovible++;
		}
		++it;
	}
}

void Juego::actualizarRecibidos() {
	std::unique_lock<std::mutex> lk(*m);
/*	while (colaDeRecibidos->empty ()) {
		cond->wait_for(lk, std::chrono);
		
	}*/
	while (!colaDeRecibidos->empty ()) {
		std::string mensaje = colaDeRecibidos->front ();
		switch (mensaje[0]) {
			case crear: this->recibirCrear (mensaje);
						break;
			case mover: this->recibirMover(mensaje);
						break;
			case disparar: this->recibirDisparar(mensaje);
						break;
			case info: 
						if (mensaje[1] == 'm')
							this->recibirObtenerInfoUnidad(mensaje);
						if (mensaje[1] == 'i')
							this->recibirObtenerInfoFabrica(mensaje);
						break;
		}
		
		colaDeRecibidos->pop ();
	}
	lk.unlock ();
}

void Juego::recibirCrear(std::string mensaje) {
	std::string idStr = mensaje.substr(1,id);
	std::string tipoStr = mensaje.substr (4,tipo);
	
	int tipo = stoi(tipoStr);
	int tiempo;
	if (tipo>=6 && tipo<=10) {
		FabricaRobots* fabricaR = FabricaRobots::getInstancia ();
		tiempo = fabricaR->getTiempo (tipo);
	} else if (tipo>=11 && tipo<=16) {
		FabricaVehiculos* fabricaV = FabricaVehiculos::getInstancia ();
		tiempo = fabricaV->getTiempo (tipo);
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
								aEstrella.getRecorrido ({inicio[0],inicio[1]},
														{(int) x,(int) y});
	movibles[idStr]->setTrayectoria(recorrido);
}

void Juego::recibirDisparar(std::string mensaje) {
	std::string idAgresor = mensaje.substr(1,id);
	std::string idAgredido = mensaje.substr(4,id);
	((Unidad*) movibles[idAgresor])->dispararA (idAgredido);
}

void Juego::recibirObtenerInfoUnidad (std::string mensaje) {
	std::cout<<"recibo(unidad): "<<mensaje<<std::endl;
	std::string idStr = mensaje.substr(1,id);
	this->enviarInfoUnidad (idStr);
}

void Juego::recibirObtenerInfoFabrica (std::string mensaje) {
	std::cout<<"recibo(edificio): "<<mensaje<<std::endl;
	std::string idStr = mensaje.substr(1,id);
	this->enviarInfoFabrica (idStr);
}

void Juego::enviarInfoUnidad (std::string id) {
	std::string mensaje = "4" + id ;
	Movible* movible = movibles[id];
	std::string tipo = agregarPadding(movible->getTipo(),2);
	std::string vida = agregarPadding(movible->getPorcentajeVida (), 3);
	mensaje += tipo + vida;
	std::cout<<"envio: "<<mensaje<<std::endl;
	colaDeEnviados.push (mensaje);
}

void Juego::enviarInfoFabrica (std::string id) {
	std::cout<<"entro a enviar info fabrica"<<std::endl;
	std::string mensaje = "7" + id;
	Edificio* edificio = edificios[id];
	std::string tipoStr = agregarPadding(edificio->getTipo(), 2);
	std::string vidaStr = agregarPadding(edificio->getPorcentajeVida (), 3);
	
	FabricaRobots* fabricaR = FabricaRobots::getInstancia ();
	FabricaVehiculos* fabricaV = FabricaVehiculos::getInstancia ();
	
	std::cout<<"tipo edificio: "<<tipoStr<<std::endl;
	int tipo = edificio->getTipo ();
	std::vector<int> vehiculosPosibles;
	std::vector<int> robotsPosibles;
	if (tipo == 5 || tipo == 3) {
		std::cout<<"entro aca"<<std::endl;
		vehiculosPosibles = 
					fabricaV->getVehiculosPosibles (edificio->getNivel ());
	}
	if (tipo == 4 || tipo == 3) {
		std::cout<<"y aca tambien"<<std::endl;
		robotsPosibles = 
					fabricaR->getRobotsPosibles (edificio->getNivel ());
	}
	
	int cantidad = vehiculosPosibles.size() + robotsPosibles.size();
	std::string cantidadStr = agregarPadding(cantidad,2);
	std::string unidadesStr = cantidadStr;
	for (int idActual : vehiculosPosibles) {
		int tiempo = fabricaV->getTiempo (idActual)/TICKS; //En segundos
		std::string tiempoStr = agregarPadding(tiempo,4);
		std::string idStr = agregarPadding(idActual,2);
		std::cout<<idStr<<std::endl;
		std::cout<<tiempoStr<<std::endl;
		unidadesStr += idStr + tiempoStr;
	}
	for (int idActual : robotsPosibles) {
		int tiempo = fabricaR->getTiempo (idActual)/TICKS; //En segundos 
		std::string tiempoStr = agregarPadding(tiempo,4);
		std::string idStr = agregarPadding(idActual,2);
		std::cout<<idStr<<std::endl;
		std::cout<<tiempoStr<<std::endl;
		unidadesStr += idStr + tiempoStr;
	}
	
	std::string construyendo = std::to_string((int) edificio->estaCreando ());
	
	mensaje += tipoStr + vidaStr + unidadesStr + construyendo;
	colaDeEnviados.push (mensaje);
}	

void Juego::enviarCrear (Objeto* objeto) {

}

void Juego::enviarMensajesEncolados() {
	while (!colaDeEnviados.empty ()) {
		std::string mensaje = colaDeEnviados.front ();
		colaDeEnviados.pop ();
		socket->SendStrWLen (mensaje);
	}
}

void Juego::run() {
	std::array<double, 2> origen = {0.0,0.0};
	std::array<double, 2> intermedio = {2.0,2.0};
	std::array<double, 2> destino = {5.0, 5.0};
	
	while (!this->hayGanador()) {
		clock_t tiempo1 = clock();
		this->actualizarRecibidos ();
//		std::cout<<"actualizo edificios"<<std::endl;
		this->actualizarEdificios();
//		std::cout<<"actualizo disparos"<<std::endl;
		this->actualizarDisparos();
//		std::cout<<"actualizo mover unidades"<<std::endl;
		this->moverUnidades ();
//		std::cout<<"actualizo chequear colisiones"<<std::endl;
		this->chequearColisiones();
//		std::cout<<"actualizo muertos"<<std::endl;
		this->eliminarMuertos();
//		std::cout<<movibles.size()<<std::endl;
		this->enviarMensajesEncolados();
		clock_t tiempo2 = clock();
		double intervaloDormir = CYCLE_TIME - 
									double(tiempo2 - tiempo1)/CLOCKS_PER_SEC;
		struct timespec req = {0};
		req.tv_sec = 0;
		req.tv_nsec = intervaloDormir*NANO;
		while (nanosleep(&req, &req) == -1); 
	}
	
}

bool Juego::hayGanador() {
	return false;
}

Juego::~Juego () { 
	//Limpiar movibles, porque son punteros
	//Limpiar inmovibles, porque son punteros
}

