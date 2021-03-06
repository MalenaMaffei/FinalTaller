#include <vector>
#include "FabricaVehiculos.h"
#include <sstream>
#include <tinyxml2.h>
#include <time.h>
#include <iomanip>
#include <iostream>
#include "constantesServer.h"
#include "Logger.h"

FabricaVehiculos::FabricaVehiculos() { 
	tinyxml2::XMLDocument xml;
	if (xml.LoadFile("vehiculos.xml")) {
		xml.PrintError();
		return;
	}	
	Logger* logger = Logger::getInstancia();
	logger->logACout("fabrica vehiculos");
	tinyxml2::XMLElement* robots = xml.FirstChildElement("VEHICULOS");
	for(tinyxml2::XMLElement* robot = robots->FirstChildElement("VEHICULO"); 
		robot != NULL; robot = robot->NextSiblingElement("VEHICULO")) {
		int tipo = atoi(robot->FirstChildElement("ID")->GetText());
		int armamento = atoi(robot->FirstChildElement("ARMAMENTO")->GetText());
		double frecuencia = 
					atof(robot->FirstChildElement("FRECUENCIA")->GetText());
		int alcance = atoi(robot->FirstChildElement("ALCANCE")->GetText());
		int resistencia = 
					atoi(robot->FirstChildElement("RESISTENCIA")->GetText());		
		int velocidad = 
					atoi(robot->FirstChildElement("VELOCIDAD")->GetText());
		int cantidad = 
					atoi(robot->FirstChildElement("CANT_FABRICA")->GetText());
		const char* tiempoStr = 
					robot->FirstChildElement("TIEMPO_FABRICA")->GetText();		
		
		struct tm tm;
		std::istringstream ss(tiempoStr);
		ss >> std::get_time(&tm, "%M:%S");
		int secs = tm.tm_min*60 + tm.tm_sec;
		int nivel = atoi(robot->FirstChildElement("NIVEL")->GetText());
		double ancho = atof(robot->FirstChildElement("ANCHO")->GetText());
		double alto = atof(robot->FirstChildElement("ALTO")->GetText());
		
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
		//Dimensiones
		anchos[tipo] = ancho;
		altos[tipo] = alto;
	}
}

Vehiculo* FabricaVehiculos::getVehiculo(int tipo) {  
	return new Vehiculo(vidas[tipo],anchos[tipo],altos[tipo],frecuencias[tipo],
					 alcances[tipo], velocidades[tipo], tipo, armamentos[tipo]);
}

int FabricaVehiculos::getTiempo(int tipo) {
	return tiempos[tipo];
}

void FabricaVehiculos::getVehiculosPosibles(int nivel, 
											std::vector<int>& tiposPosibles) {
	for (const auto& actual: niveles) {
		int nivelActual = actual.second;
		if (nivelActual>nivel) {
			continue;
		}
		int tipoActual = actual.first;
		tiposPosibles.push_back(tipoActual);
	}
}

double FabricaVehiculos::getAlcance(int tipo) {
	return (double) alcances[tipo];
}
