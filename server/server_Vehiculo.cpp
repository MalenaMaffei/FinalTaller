/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: usuario
 * 
 * Created on 30 de mayo de 2017, 00:03
 */

#include "server_Vehiculo.h"

#include "server_Robot.h"

Vehiculo::Vehiculo(int vida, double ancho, double alto, 
					int frecuenciaDisparo, int alcance, 
					int velocidad, int tipo) : 
								Unidad(vida, ancho, alto,
									frecuenciaDisparo, alcance, 
									velocidad, tipo), 
									conductor(NULL) { }

bool Vehiculo::addConductor(Robot* conductor) { 
	//No me puedo subir a vehiculo ocupado
	if (this->conductor) {
		return false;
	}
	this->conductor = conductor;
	return true;
}

Vehiculo::~Vehiculo () { }

