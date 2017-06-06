/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Robot.cpp
 * Author: usuario
 * 
 * Created on 30 de mayo de 2017, 00:39
 */

#include "server_Robot.h"

#include "server_Unidad.h"


Robot::Robot(int vida, double ancho, double alto, 
            int frecuenciaDisparo, int alcance, 
			 int tipoArmamento, int velocidad, int tipo) : Unidad(vida, ancho, alto,
									frecuenciaDisparo, alcance, 
									tipoArmamento, velocidad, tipo) { }

bool Robot::subirA(Vehiculo* vehiculo) {
	return vehiculo->addConductor (this);
}

Robot::~Robot () { }

