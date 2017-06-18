/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.cpp
 * Author: usuario
 * 
 * Created on 18 de junio de 2017, 14:53
 */

#include "Mensaje.h"

Mensaje::Mensaje(std::string mensaje, int id) : mensaje(mensaje), id(id) { }

std::string Mensaje::getMensaje() {
	return mensaje;
}

int Mensaje::getId() {
	return id;
}

Mensaje::~Mensaje () { }

