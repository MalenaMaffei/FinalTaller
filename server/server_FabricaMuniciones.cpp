/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaMuniciones.cpp
 * Author: usuario
 * 
 * Created on 27 de mayo de 2017, 17:30
 */

#include "server_FabricaMuniciones.h"
#include <iostream>
#include <tinyxml2.h>

enum TipoDeMunicion{
	BALA,
	LANZALLAMA,
	ALTO_CALIBRE,
	LASER,
	MISIL
};

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
	//Por ahora el tamaño de las balas es ancho = 0.1 y alto = 0.1
	//TODO
	//Por ahora la vida de la bala es igual al daño que hace, y cuando impacta,
	//se resta su propia vida
	//Velocidad 1 por ahora
	std::cout<<municiones[tipo]<<std::endl;
	return new Municion(municiones[tipo],0.1,0.1,tipo,municiones[tipo],1);
}
