/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armamento.cpp
 * Author: usuario
 * 
 * Created on 27 de mayo de 2017, 16:55
 */

#include "server_Armamento.h"
#include "server_FabricaMuniciones.h"

#include <iostream>

Armamento::Armamento (int tipo) : tipo(tipo) { }

Armamento::Armamento (const Armamento& orig) { }

Municion* Armamento::dispararA (std::array<double,2> posicion, Objeto& objetivo) {
	FabricaMuniciones* fabricaMuniciones = FabricaMuniciones::getInstancia();
	Municion* municion = fabricaMuniciones->getMunicion (tipo);
	municion->setPosicion (posicion);
	municion->mover (objetivo.getPosicion());
	return municion;
}

Municion Armamento::getMunicion(int tipo){
  
}

Armamento::~Armamento () { }

