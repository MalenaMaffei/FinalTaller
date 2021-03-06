
#include <tinyxml2.h>
#include <iostream>
#include "FabricaTerrenos.h"

FabricaTerrenos::FabricaTerrenos() { 
 	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile("terrenos.xml")) {
 		xml.PrintError();
 		return;
 	}
 
 	tinyxml2::XMLElement* terrenos = xml.FirstChildElement("TERRENOS");
		
	for(tinyxml2::XMLElement* terreno = terrenos->FirstChildElement("TERRENO"); 
		terreno != NULL; terreno = terreno->NextSiblingElement("TERRENO")) {
		int tipo = atoi(terreno->FirstChildElement("ID")->GetText());
		double velRobot = 
					atof(terreno->FirstChildElement("VEL_ROBOTS")->GetText());
		double velVehiculo = 
				atof(terreno->FirstChildElement("VEL_VEHICULOS")->GetText());
		
		velocidadesRobots[tipo] = velRobot;
		velocidadesVehiculos[tipo] = velVehiculo;
	} 	
}

Terreno FabricaTerrenos::getTerreno(int tipo) {
	return Terreno(tipo, velocidadesRobots[tipo], velocidadesVehiculos[tipo]);
}

FabricaTerrenos::~FabricaTerrenos() { }

