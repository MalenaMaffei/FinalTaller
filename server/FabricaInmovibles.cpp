/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaInmovibles.cpp
 * Author: usuario
 * 
 * Created on 24 de junio de 2017, 12:03
 */

#include "FabricaInmovibles.h"
#include "server_constants.h"
#include <tinyxml2.h>

FabricaInmovibles::FabricaInmovibles () {
	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile("inmovibles.xml")) {
 		xml.PrintError ();
 		return ;
 	}
 
 	tinyxml2::XMLElement* inmovibles = xml.FirstChildElement ("INMOVIBLES");
		

	for(tinyxml2::XMLElement* inmovible = inmovibles->FirstChildElement("INMOVIBLE"); 
		inmovible != NULL; inmovible = inmovible->NextSiblingElement("INMOVIBLE")) {
		
		int tipo = atoi(inmovible->FirstChildElement("ID")->GetText ());
		tinyxml2::XMLElement* vidaXML= inmovible->FirstChildElement ("VIDA");
		if (vidaXML) {
			int vida = atoi(vidaXML->GetText ());
			this->vidas[tipo] = vida;
		}
		double ancho = atof(inmovible->FirstChildElement ("ANCHO")->GetText ());
		double alto = atof(inmovible->FirstChildElement ("ALTO")->GetText ());
		
		this->anchos[tipo] = ancho;
		this->altos[tipo] = alto;
	}
}

Bloque* FabricaInmovibles::getBloque(int tipo, double x, double y, std::string id) {
	Bloque* bloque = new Bloque(vidas[tipo],anchos[tipo],altos[tipo],tipo);
	bloque->setId (id);
	bloque->setPosicion ({x,y});
	return bloque;
}

Bandera* FabricaInmovibles::getBandera(int tipo, double x, double y, std::string id) {
	Bandera* bandera = new Bandera(anchos[tipo],altos[tipo],tipo);
	bandera->setId (id);
	bandera->setPosicion ({x,y});
	return bandera;
}

Inmovible* FabricaInmovibles::getInmovible(int tipo, double x, double y, std::string id) {
	if (tipo == 0)
		return this->getBloque (tipo,x,y,id);
	if (tipo == 2)
		return this->getBandera (tipo,x,y,id);
	return NULL;
}

FabricaInmovibles::~FabricaInmovibles () { }

