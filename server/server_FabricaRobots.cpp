/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaRobots.cpp
 * Author: usuario
 * 
 * Created on 30 de mayo de 2017, 10:02
 */

#include "server_FabricaRobots.h"
#include <sstream>
#include <tinyxml2.h>
#include <time.h>
#include <iomanip>
#include "server_constants.h"
#include <iostream>
#include "Logger.h"

FabricaRobots::FabricaRobots () { 
	tinyxml2::XMLDocument xml;
	if (xml.LoadFile ("robots.xml")) {
		xml.PrintError ();
		return;
	}	
	Logger* logger = Logger::getInstancia();
	logger->logACout("fabrica robots");
	tinyxml2::XMLElement* robots = xml.FirstChildElement ("ROBOTS");
	for(tinyxml2::XMLElement* robot = robots->FirstChildElement("ROBOT"); 
		robot != NULL; robot = robot->NextSiblingElement("ROBOT")) {
		
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
		int secs = tm.tm_min*60 + tm.tm_sec;
		int nivel = atoi(robot->FirstChildElement ("NIVEL")->GetText());
		
		//Caracteristicas de robot
		armamentos[tipo] = armamento;
		frecuencias[tipo] = TICKS/frecuencia;
		alcances[tipo] = alcance;
		vidas[tipo] = resistencia;
		velocidades[tipo] = velocidad;
		//Reqisitos de creación
		cantidades[tipo] = cantidad;
		tiempos[tipo] = secs*TICKS;
		niveles[tipo] = nivel;
	}
}

Robot* FabricaRobots::getRobot(int tipo) {  
	 //Por ahora todos los robots son de 1x1
	 //TODO
	 //Agregar velocidad base
	return new Robot(vidas[tipo],1,1,frecuencias[tipo],
					 alcances[tipo], velocidades[tipo],tipo, armamentos[tipo]);
}

int FabricaRobots::getCantidad(int tipo) {
	return cantidades[tipo];
}

int FabricaRobots::getTiempo(int tipo) {
	return tiempos[tipo];
}

void FabricaRobots::getRobotsPosibles(int nivel, std::vector<int>& tiposPosibles) {
	for (const auto& actual: niveles) {
		int nivelActual = actual.second;
		if (nivelActual>nivel) {
			continue;
		}
		int tipoActual = actual.first;
		tiposPosibles.push_back(tipoActual);
	}
}

double FabricaRobots::getAlcance(int tipo) {
	return (double) alcances[tipo];
}