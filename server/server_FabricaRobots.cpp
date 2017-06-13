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

FabricaRobots* FabricaRobots::instancia = NULL;

FabricaRobots::FabricaRobots () { 
	tinyxml2::XMLDocument xml;
	if (xml.LoadFile ("robots.xml")) {
		xml.PrintError ();
		return;
	}	
	std::cout<<"fabrica robots"<<std::endl;
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
		std::cout<<"tiempo: "<<std::endl;
		std::cout<<tm.tm_min<<std::endl;
		std::cout<<tm.tm_sec<<std::endl;
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
		std::cout<<tipo<<std::endl;
		std::cout<<secs*TICKS<<std::endl;
		niveles[tipo] = nivel;
	}
}

FabricaRobots* FabricaRobots::getInstancia() {
	if (!instancia) {
		instancia = new FabricaRobots();
	}
	return instancia;
}

Robot* FabricaRobots::getRobot(int tipo) {
	/*        Robot(int vida, double ancho, double alto, 
                int frecuenciaDisparo, int alcance, 
                int tipoArmamento);
	 */
  
	 //Por ahora todos los robots son de 1x1
	 //TODO
	 //Agregar velocidad base
	return new Robot(vidas[tipo],1,1,frecuencias[tipo],
					 alcances[tipo],armamentos[tipo], velocidades[tipo],tipo);
}

int FabricaRobots::getCantidad(int tipo) {
	return cantidades[tipo];
}

int FabricaRobots::getTiempo(int tipo) {
	return tiempos[tipo];
}

std::vector<int> FabricaRobots::getRobotsPosibles(int nivel) {
	std::vector<int> tiposPosibles;
	for (const auto& actual: niveles) {
		int nivelActual = actual.second;
		if (nivelActual>nivel) {
			continue;
		}
		int tipoActual = actual.first;
		tiposPosibles.push_back(tipoActual);
	}
	return tiposPosibles;
}