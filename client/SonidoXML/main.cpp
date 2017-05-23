
#include "Reproductor.h"
#include <tinyxml2.h>
#include <iostream>
#include "SeleccionadoHUD.h"
#include "GeneradorMapa.h"
#include <gtkmm/application.h>
#include <array>
#include "GeneradorMapa.h"

#define MUS_NAME "musica/music_desert.ogg"
#define FX_NAME "efectos/EXP1.wav"
#define XML_NAME "stats.xml"

int main( int argc, char* args[] )
{
/*	auto app = Gtk::Application::create(argc, args, "org.gtkmm.example");
  
	SeleccionadoHUD grunt_hud;
	

//	grunt_hud.seleccionarFabrica();
	
	app->run(grunt_hud);*/

	GeneradorMapa generador;
	generador.generarMapa ();
  
}