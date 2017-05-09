
#include "Reproductor.h"
#include <tinyxml2.h>
#include <iostream>

#define MUS_NAME "musica/music_desert.ogg"
#define FX_NAME "efectos/EXP1.wav"
#define XML_NAME "stats.xml"

int main( int argc, char* args[] )
{
/*	Reproductor reproductor;
	
	reproductor.reproducirMusica (FX_NAME);	
	reproductor.reproducirMusica (MUS_NAME);*/

  	tinyxml2::XMLDocument xml;

	if (xml.LoadFile(XML_NAME)) {
		xml.PrintError ();
		return -1;
	}

	tinyxml2::XMLElement* z = xml.FirstChildElement ("Z");
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
	
	std::cout<<"Grunt dano: "<<grunt_dano->GetText ()<<std::endl;
	
	return 0;
}