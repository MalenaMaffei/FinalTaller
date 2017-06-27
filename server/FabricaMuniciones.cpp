
#include "FabricaMuniciones.h"
#include <iostream>
#include "Logger.h"
#include <tinyxml2.h>

#define VEL_MUNICION 1

FabricaMuniciones::FabricaMuniciones() {
	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile("municiones.xml")) {
 		xml.PrintError();
 		return;
 	}
 
 	tinyxml2::XMLElement* municiones = xml.FirstChildElement("MUNICIONES");
		

	for(tinyxml2::XMLElement* municion = 
							municiones->FirstChildElement("MUNICION"); 
		municion != NULL; municion = 
							municion->NextSiblingElement("MUNICION")) {
				int tipo = atoi(municion->FirstChildElement("ID")->GetText());
		int danio = atoi(municion->FirstChildElement("DANIO")->GetText());
		double ancho = atof(municion->FirstChildElement("ANCHO")->GetText());
		double alto = atof(municion->FirstChildElement("ALTO")->GetText());
		
		this->municiones[tipo] = danio;
		this->anchos[tipo] = ancho;
		this->altos[tipo] = alto;
	}
}

Municion* FabricaMuniciones::getMunicion(int tipo) {
	return new Municion(municiones[tipo],anchos[tipo],altos[tipo],tipo,
					 municiones[tipo],VEL_MUNICION);
}
