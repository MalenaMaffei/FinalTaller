
#include "server_Casillero.h"
#include <stdlib.h>
#include <iostream>

Casillero::Casillero(Terreno &&terreno) : 
									terreno(std::move(terreno)) {
	ocupado = false;
}

Casillero::Casillero(const Casillero& orig) : terreno(orig.terreno), 
												ocupado(orig.ocupado){
	
}

Casillero& Casillero::operator=(const Casillero& orig) {
	terreno = orig.terreno;
	ocupado = orig.ocupado;
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

