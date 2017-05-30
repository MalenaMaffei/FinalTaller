/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.cpp
 * Author: usuario
 * 
 * Created on 30 de mayo de 2017, 14:55
 */

#include "server_Bloque.h"
#include <iostream>

Bloque::Bloque (int vida, double ancho, double alto) : Inmovible(vida, ancho, 
																 alto) { }

void Bloque::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Bloque::colisionar(Municion& municion) {
	this->recibirDanio(municion.getDanio ());
}

void Bloque::colisionar (Unidad& personaje) {
	//No hago nada si colisiona una persona con un bloque
}

void Bloque::colisionar(Bloque& bloque) {
	//No hago nada si colisiona bloque con bloque
}


Bloque::~Bloque () { }

