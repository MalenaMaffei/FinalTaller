
#include "server_Casillero.h"
#include <stdlib.h>
#include <iostream>

Casillero::Casillero(Terreno &&terreno) : terreno(std::move(terreno)) {
}

Casillero::Casillero(const Casillero& orig) : terreno(orig.terreno) { }

Casillero& Casillero::operator=(const Casillero& orig) {
	terreno = orig.terreno;
	return *this;
}

double Casillero::getFactorTerreno(Movible* movible) {
	return terreno.getFactor(movible);
}

int Casillero::getTipoTerreno () {
	return terreno.getTipo();
}

Casillero::~Casillero() {}

