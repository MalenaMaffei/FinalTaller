/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaVehiculos.cpp
 * Author: usuario
 * 
 * Created on 30 de mayo de 2017, 11:14
 */

#include "server_FabricaVehiculos.h"
#include <sstream>
#include <tinyxml2.h>
#include <time.h>
#include <iomanip>
#include <iostream>

FabricaVehiculos* FabricaVehiculos::instancia = NULL;

FabricaVehiculos::FabricaVehiculos () { 
	tinyxml2::XMLDocument xml;
	if (xml.LoadFile ("vehiculos.xml")) {
		xml.PrintError ();
		return;
	}	
		
	tinyxml2::XMLElement* robots = xml.FirstChildElement ("VEHICULOS");
	for(tinyxml2::XMLElement* robot = robots->FirstChildElement("VEHICULO"); 
		robot != NULL; robot = robot->NextSiblingElement("VEHICULO")) {
		int tipo = atoi(robot->FirstChildElement("ID")->GetText ());
		int armamento = atoi(robot->FirstChildElement("ARMAMENTO")->GetText ());
		double frecuencia = atof(robot->FirstChildElement ("FRECUENCIA")->GetText ());
		int alcance = atoi(robot->FirstChildElement ("ALCANCE")->GetText());
		int resistencia = atoi(robot->FirstChildElement ("RESISTENCIA")->GetText());		
		int velocidad = atoi(robot->FirstChildElement ("VELOCIDAD")->GetText());
		int cantidad = atoi(robot->FirstChildElement ("CANT_FABRICA")->GetText());
		const char* tiempoStr = robot->FirstChildElement ("TIEMPO_FABRICA")->GetText();
		struct tm tm;
		std::istringstream ss(tiempoStr);
		ss >> std::get_time(&tm, "%M:%S");
		std::time_t tiempo = mktime(&tm);
		int nivel = atoi(robot->FirstChildElement ("NIVEL")->GetText());
		
		//Caracteristicas de robot
		armamentos[tipo] = armamento;
		frecuencias[tipo] = frecuencia;
		alcances[tipo] = alcance;
		vidas[tipo] = resistencia;
		velocidades[tipo] = velocidad;
		//Reqisitos de creación
		cantidades[tipo] = cantidad;
		tiempos[tipo] = tiempo;
		niveles[tipo] = nivel;
	}
}

FabricaVehiculos* FabricaVehiculos::getInstancia() {
	if (!instancia) {
		instancia = new FabricaVehiculos();
	}
	return instancia;
}

Vehiculo* FabricaVehiculos::getVehiculo(int tipo) {  
	//Por ahora todos los vehiculos son de 1x1
	//Agregar velocidad base
	//TODO
	//El conductor se agrega en la fabrica fisica
	return new Vehiculo(vidas[tipo],1,1,frecuencias[tipo],
					 alcances[tipo],armamentos[tipo]);
}
