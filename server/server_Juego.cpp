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
#include "server_Unidad.h"
#include "server_FabricaRobots.h"
#include "server_FabricaVehiculos.h"
#include "server_Bloque.h"
#include <array>
#include <iostream>

enum equipos {
	EQUIPO_1,
	EQUIPO_2 
};

Juego::Juego () : mapa(Mapa("mapa.map")) { 
	//Reemplazar por inicializar juego
//	FabricaRobots* fabricaRobots = FabricaRobots::getInstancia ();
	FabricaVehiculos* fabricaV = FabricaVehiculos::getInstancia ();
	movibles.push_back (fabricaV->getVehiculo (0));
	movibles.push_back (fabricaV->getVehiculo (0));
	
//	std::cout<<"creo bloque"<<std::endl;
	inmovibles.push_back (new Bloque(2,1,1)); //Agrego un bloque de 1x1
//	std::cout<<"exito"<<std::endl;
}

void Juego::eliminarMuertos() {

	std::vector<Movible*>::iterator it1 = movibles.begin ();
	while (it1!=movibles.end()) {
		int vida = (*it1)->getVida();
		if (vida <= 0) {
			Movible* borrado = *it1;
			it1 = movibles.erase (it1);
			delete borrado;
			continue;
		}
		++it1;
	}
	std::vector<Inmovible*>::iterator it2 = inmovibles.begin ();
	while (it2!=inmovibles.end()) {
		int vida = (*it2)->getVida();
		if (vida <= 0) {
			Inmovible* borrado = *it2;
			it2 = inmovibles.erase (it2);
			delete borrado;
			continue;
		}
		++it2;
	}
}

void Juego::moverUnidades() {
	for (Movible* movible: movibles) {
		movible->mover ();
//		std::array<double,2> pos = movible->getPosicion ();
//		std::cout<<pos[0]<<","<<pos[1]<<std::endl;
	}
//	std::cout<<"===="<<std::endl;
}

void Juego::chequearColisiones () {
  
  
	//Cheque con objetos movibles
	for (size_t i=0; i<movibles.size (); ++i) {
		Movible* mov1 = movibles[i];
		for (size_t j=0; j<inmovibles.size(); ++j){
			Inmovible* inMov2 = inmovibles[j];
			if (mov1->colisiona(*inMov2)) {
				inMov2->colisionar (*mov1);
				mov1->colisionar(*inMov2);
			}
		}
		for (size_t j=0; j<movibles.size(); ++j){
			if (i == j) continue;	//No comparo con si mismo
			Movible* mov2 = movibles[j];
			if (mov1->colisiona(*mov2)) {
				mov1->colisionar(*mov2);
			}
		}

	}
}

void Juego::run() {
	std::array<double, 2> origen = {0.0,0.0};
	std::array<double, 2> intermedio = {7.0,7.0};
	std::array<double, 2> destino = {15.0, 15.0};

	movibles[0]->setPosicion(origen);
	movibles[0]->setEquipo(EQUIPO_1);
	movibles[1]->setPosicion(destino);
	movibles[1]->setEquipo(EQUIPO_2);

	inmovibles[0]->setPosicion(intermedio); //Bala deberia imapactar bloque
	
	Municion* municion = ((Unidad*) movibles[0])->dispararA (*movibles[1]); //Pruebo disparar a otro personaje
	
	movibles.push_back (municion);
	
	std::cout<<movibles[1]->getVida()<<std::endl;
	
	for (int i=0;i<30;i++) { //Esto deberia ser un while (no hay ganador), ciclo del juego
		this->moverUnidades ();
		this->chequearColisiones();
		this->eliminarMuertos();
	}
	
	std::cout<<movibles[1]->getVida()<<std::endl;
}

Juego::~Juego () { 
	//Limpiar movibles, porque son punteros
	//Limpiar inmovibles, porque son punteros
}

