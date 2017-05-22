#include "server_Mapa.h"

Mapa::Mapa() {}

void Mapa::AEstrella(Casillero origen, Casillero destino) {
	AEstrella camino(origen, destino);
	std::vector<Casillero> recorrido;
	camino.getRecorrido(recorrido);
}

Mapa::~Mapa() {

}

