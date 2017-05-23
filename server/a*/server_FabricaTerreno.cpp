/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaTerreno.cpp
 * Author: usuario
 * 
 * Created on 23 de mayo de 2017, 16:35
 */

#include "server_FabricaTerreno.h"

FabricaTerreno::FabricaTerreno () { 

	tinyxml2::XMLDocument xml;
 
 	if (xml.LoadFile("terrenos.xml")) {
 		xml.PrintError ();
 		return -1;
 	}
 
 	tinyxml2::XMLElement* terrenos = xml.FirstChildElement ("TERRENOS");

/*	for (terrenos->)
	
 	tinyxml2::XMLElement* armamentos = z->FirstChildElement ("ARMAMENTO");
 	tinyxml2::XMLElement* bala = armamentos->FirstChildElement ("BALA");
 	tinyxml2::XMLElement* dano = bala->FirstChildElement ("DAÑO");
 	tinyxml2::XMLElement* explosivo = bala->FirstChildElement ("EXPLOSIVO");
 	std::cout<<"Daño: "<<dano->GetText ()<<std::endl;	
 	std::cout<<"Explosivo: "<<explosivo->GetText () <<std::endl;
 	
 	tinyxml2::XMLElement* robots = z->FirstChildElement ("ROBOTS");
 	tinyxml2::XMLElement* grunt = robots->FirstChildElement ("GRUNT");
 	tinyxml2::XMLElement* grunt_armamento = grunt->FirstChildElement("ARMAMENTO");
 	const char* text = grunt_armamento->GetText ();
 	
 	std::cout<<"Grunt armamento: "<<text<<std::endl;
 
 	tinyxml2::XMLElement* grunt_dano = armamentos->FirstChildElement (text)->FirstChildElement ("DAÑO");
 	
 	std::cout<<"Grunt dano: "<<grunt_dano->GetText ()<<std::endl;*/
 	
 	return 0;
  
  

}

FabricaTerreno::FabricaTerreno (const FabricaTerreno& orig) { }

FabricaTerreno::~FabricaTerreno () { }

