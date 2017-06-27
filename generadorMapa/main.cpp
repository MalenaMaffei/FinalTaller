
#include "GeneradorMapa.h"

int main( int argc, char* args[] )
{
	GeneradorMapa generador;
	generador.generarMapa("../server/mapa.map");
	generador.generarObjetos("../server/configuracion.xml");
}
