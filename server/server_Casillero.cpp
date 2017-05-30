
#include "server_Casillero.h"
#include <stdlib.h>

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

double Casillero::getFactorTerreno() {
	return terreno.getFactor();
}

Casillero::~Casillero() {}

