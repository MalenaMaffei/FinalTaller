/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManejadorIDs.cpp
 * Author: usuario
 * 
 * Created on 24 de junio de 2017, 13:19
 */

#include "ManejadorIDs.h"

ManejadorIDs::ManejadorIDs () : proximoIDMovible (0),
								proximoIDEdificio (0),
								proximoIDInmovible (0),
								proximoIDMunicion (0) { }

std::string ManejadorIDs::getIDMunicion() {
	std::string id = rellenador.rellenar(proximoIDMunicion++,3);
	return id;
}

std::string ManejadorIDs::getIDEdificio() {
	std::string id = "i" + rellenador.rellenar(proximoIDInmovible++,2);
	return id;	
}

std::string ManejadorIDs::getIDMovible() {
	std::string id ="m" + rellenador.rellenar(proximoIDMovible++,2);
	return id;
}

std::string ManejadorIDs::getIDInmovible() {
	std::string id = "i" + rellenador.rellenar(proximoIDInmovible++,2);
	return id;
}

ManejadorIDs::~ManejadorIDs () { }


