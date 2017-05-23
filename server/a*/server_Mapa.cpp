#include <fstream>

#include <fstream>
#include "server_Mapa.h"
#include "../server_GeneradorMapa.h"


Mapa::Mapa() {
	//Creo archivo con mapa
	GeneradorMapa generadorMapa;
	generadorMapa.generarMapa ("mapa.map");
	
	std::ifstream archivoMapa;	
	archivoMapa.open("mapa.map");

	std::string fila;
	std::string posicion;
	size_t i = 0;
	size_t j = 0;
	while (! archivoMapa.eof() ){
		getline (archivoMapa,fila);
		std::stringstream posiciones(fila);
		while (!getline(posiciones,posicion)) {
			mapa[i][j] = Casillero ();
			j++;
		}
		i++;
	}
	
	std::vector< std::vector<Casillero> >::iterator row;
	std::vector< Casillero >::iterator col;
	for (row = mapa.begin(); row != mapa.end(); ++row) {
    	for (col = row->begin(); col != row->end(); ++col) {
        	
    	}
    }
}

void Mapa::AEstrella(Casillero origen, Casillero destino) {
	AEstrella camino(origen, destino);
	std::vector<Casillero> recorrido;
	camino.getRecorrido(recorrido);
}

Mapa::~Mapa() {

}

