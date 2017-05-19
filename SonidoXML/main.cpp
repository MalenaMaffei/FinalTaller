
#include "Reproductor.h"
#include <tinyxml2.h>
#include <iostream>
#include "CharacterHUD.h"
#include <gtkmm/application.h>

#define MUS_NAME "musica/music_desert.ogg"
#define FX_NAME "efectos/EXP1.wav"
#define XML_NAME "stats.xml"

int main( int argc, char* args[] )
{
	auto app = Gtk::Application::create(argc, args, "org.gtkmm.example");
  
	CharacterHUD grunt_hud;
  
	return app->run(grunt_hud);
	return 0;
}