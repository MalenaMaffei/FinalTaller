
#include "GeneradorMapa.h"

int main( int argc, char* args[] )
{
	GeneradorMapa generador;
	generador.generarMapa ("mapa.map");
	generador.generarObjetos("configuracion.xml");
}