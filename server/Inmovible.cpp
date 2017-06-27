
#include "Inmovible.h"

Inmovible::Inmovible(int vida, double ancho, double alto, int tipo) :	
															Objeto(vida, 
															ancho, 
															alto, tipo) {}


Inmovible::Inmovible(const Inmovible& orig) : Objeto(orig.vida, orig.ancho, 
											   orig.alto, orig.tipo) { }

Inmovible& Inmovible::operator=(const Inmovible& orig) {
	vida = orig.vida;
	ancho = orig.ancho;
	alto = orig.alto;
	tipo = orig.tipo;
	return *this;
}

Inmovible::~Inmovible() { }

