
#include "server_Casillero.h"
#include <stdlib.h>
#include <iostream>

Casillero::Casillero(Terreno &&terreno) : 
									ocupado(false),
									terreno(std::move(terreno)) {
}

Casillero::Casillero(const Casillero& orig) : ocupado(orig.ocupado),
											terreno(orig.terreno) { }

Casillero& Casillero::operator=(const Casillero& orig) {
	ocupado = orig.ocupado;
	terreno = orig.terreno;
	return *this;
}

bool Casillero::estaOcupado() {
	return ocupado;
}

double Casillero::getFactorTerreno(Movible* movible) {
	return terreno.getFactor(movible);
}

int Casillero::getTipoTerreno () {
	return terreno.getTipo();
}

Casillero::~Casillero() {}

