#include "server_Mapa.h"

Mapa::Mapa() {
	vector< vector<Casillero> >::iterator row;
	vector<Casillero>::iterator col;
	for (row = mapa.begin(); row != mapa.end(); ++rpw) {
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

