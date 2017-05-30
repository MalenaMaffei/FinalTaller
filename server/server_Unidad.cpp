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
					  int tipoArmamento) : Movible(vida, ancho, alto),
										frecuenciaDisparo(frecuenciaDisparo),
										alcance(alcance),
										armamento(Armamento(tipoArmamento)) { }

Municion* Unidad::dispararA(Objeto& objetivo) {
	Municion* municion = armamento.dispararA(getPosicion (), objetivo);
	municion->setEquipo (idEquipo);
	return municion;
}

Unidad::~Unidad () { }

void Unidad::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Unidad::colisionar(Municion& municion) {
	if (idEquipo == municion.getEquipo ()) {
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