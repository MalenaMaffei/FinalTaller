/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Robot.cpp
 * Author: usuario
 * 
 * Created on 27 de mayo de 2017, 16:45
 */

#include "server_Unidad.h"
#include <iostream>

Unidad::Unidad (int vida, double ancho, double alto, 
					  int frecuenciaDisparo, int alcance, 
					  int tipoArmamento, int velocidad, int tipo) : 
										Movible(vida, ancho, alto, velocidad, 
											 tipo),
										frecuenciaDisparo(frecuenciaDisparo),
										alcance(alcance),
										armamento(Armamento(tipoArmamento)),
										estado(REPOSO),
										tiempoADisparo(0),
										bandera(false) { }

void Unidad::dispararA(std::string objetivo) {
//	Municion* municion = armamento.dispararA(getPosicion (), objetivo);
//	municion->setEquipo (idEquipo);
	this->objetivo = objetivo;
	estado = DISPARAR;
}

Unidad::~Unidad () { }

void Unidad::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Unidad::colisionar(Municion& municion) {
	if (idEquipo == municion.getEquipo ()) {
		std::cout<<"son delmismo eqiop en unidad"<<std::endl;
		return;
	}
	this->recibirDanio(municion.getDanio ());
}

void Unidad::colisionar(Unidad& personaje) {
	this->retroceder ();
	destino = posicion; //Si colisiono con otro personaje me quedo quieto
	//En un futuro podría recalcular camino a destino
}

void Unidad::colisionar(Bloque& bloque) {
	this->retroceder ();
	destino = posicion;
}

void Unidad::colisionar(Edificio& edificio) {
	this->retroceder ();
	destino = posicion;
}

void Unidad::colisionar(Bandera& bandera) {
	if (bandera.getEquipo() != idEquipo)
		this->bandera = true;
}


std::string Unidad::puedeDisparar () {
	if (estado == DISPARAR && tiempoADisparo == 0 && !objetivo.empty()) {
		tiempoADisparo = frecuenciaDisparo;
		return objetivo;
	}
	if (tiempoADisparo)
		tiempoADisparo--;
	return std::string();	//empty string
}

bool Unidad::superaMaxDistancia () {
	return false;
}

bool Unidad::obtuvoBandera () {
	if (bandera) {
		bandera = false;
		return true;
	}
	return false;
}
