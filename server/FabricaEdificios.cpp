/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaEdificios.cpp
 * Author: usuario
 * 
 * Created on 23 de junio de 2017, 12:06
 */

#include <tinyxml2.h>

#include "FabricaEdificios.h"

FabricaEdificios::FabricaEdificios () {
	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile("edificios.xml")) {
 		xml.PrintError ();
 		return ;
 	}
 
 	tinyxml2::XMLElement* edificios = xml.FirstChildElement ("EDIFICIOS");
		

	for(tinyxml2::XMLElement* edificio = edificios->FirstChildElement("EDIFICIO"); 
		edificio != NULL; edificio = edificio->NextSiblingElement("EDIFICIO")) {
		
		int tipo = atoi(edificio->FirstChildElement("ID")->GetText ());
		int vida = atoi(edificio->FirstChildElement ("VIDA")->GetText ());
		double ancho = atof(edificio->FirstChildElement ("ANCHO")->GetText ());
		double alto = atof(edificio->FirstChildElement ("ALTO")->GetText ());
		
		this->vidas[tipo] = vida;
		this->anchos[tipo] = ancho;
		this->altos[tipo] = alto;
	}
}

Edificio* FabricaEdificios::getEdificio(int tipo, int equipo, 
										double x, double y, std::string id) { 
	Edificio* edificio =  new Edificio(vidas[tipo],anchos[tipo],altos[tipo],equipo,tipo);
	edificio->setPosicion ({x,y});
	edificio->setId (id);
	return edificio;
}

FabricaEdificios::~FabricaEdificios () { }
