
#include "server_FabricaMuniciones.h"
#include <iostream>
#include "Logger.h"
#include <tinyxml2.h>

FabricaMuniciones::FabricaMuniciones() {
	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile("municiones.xml")) {
 		xml.PrintError ();
 		return ;
 	}
 
 	tinyxml2::XMLElement* municiones = xml.FirstChildElement ("MUNICIONES");
		

	for(tinyxml2::XMLElement* municion = municiones->FirstChildElement("MUNICION"); 
		municion != NULL; municion = municion->NextSiblingElement("MUNICION")) {
		
		int tipo = atoi(municion->FirstChildElement("ID")->GetText ());
		int danio = atoi(municion->FirstChildElement ("DANIO")->GetText ());
		
		this->municiones[tipo] = danio;
	}
}

Municion* FabricaMuniciones::getMunicion(int tipo) {
	//Por ahora el tamaño de las balas es ancho = 0.3 y alto = 0.3
	//TODO
	//Velocidad 1 por ahora
	Logger* logger = Logger::getInstancia();
	return new Municion(municiones[tipo],0.3,0.3,tipo,municiones[tipo],1);
}
