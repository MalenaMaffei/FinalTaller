/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bandera.cpp
 * Author: usuario
 * 
 * Created on 4 de junio de 2017, 17:24
 */

#include "server_Bandera.h"
#include "server_Movible.h"
#include "server_Unidad.h"
#include <iostream>

Bandera::Bandera (double ancho, double alto, int tipo) : Inmovible(0, ancho, 
															alto, tipo), 
												idEquipo(-1) { }

bool Bandera::estaVivo() {
	return true;
}

void Bandera::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Bandera::colisionar(Municion& municion) {
	//No hago nada si colisiona una municion con una bandera
}

void Bandera::colisionar (Unidad& personaje) {
	//No hago nada si colisiona una persona con un bandera
	idEquipo = personaje.getEquipo ();
}

void Bandera::colisionar(Bloque& bloque) {
	//No hago nada si colisiona bloque con bandera
}

void Bandera::colisionar(Bandera& bandera) {
	//No hago nada si colisiona bandera con bandera
}

void Bandera::colisionar(Edificio& edificio) {
	//No hago nada si colisiona edificio con bandera
}

int Bandera::getEquipo() {
	return idEquipo;
}

Bandera::~Bandera () { }
