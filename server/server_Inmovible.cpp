/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inmovible.cpp
 * Author: usuario
 * 
 * Created on 30 de mayo de 2017, 14:28
 */

#include "server_Inmovible.h"

Inmovible::Inmovible (int vida, double ancho, double alto, int tipo) :	
															Objeto(vida, 
															ancho, 
															alto, tipo) {}


Inmovible::Inmovible (const Inmovible& orig) : Objeto(orig.vida, orig.ancho, 
											   orig.alto, orig.tipo) { }

Inmovible& Inmovible::operator=(const Inmovible& orig) {
	vida = orig.vida;
	ancho = orig.ancho;
	alto = orig.alto;
	tipo = orig.tipo;
	return *this;
}

Inmovible::~Inmovible () { }

