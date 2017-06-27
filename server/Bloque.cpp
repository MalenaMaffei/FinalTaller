
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(int vida, double ancho, double alto, int tipo) : 
														Inmovible(vida, ancho, 
																alto, tipo) { }

void Bloque::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Bloque::colisionar(Municion& municion) {
	this->recibirDanio(municion.getDanio());
}

void Bloque::colisionar(Unidad& personaje) {
	//No hago nada si colisiona una Unidad con un Bloque
}

void Bloque::colisionar(Bloque& bloque) {
	//No hago nada si colisiona un Bloque con un Bloque
}

void Bloque::colisionar(Bandera& bandera) {
	//No hago nada si colisiona una Bandera con un Bloque
} 

void Bloque::colisionar(Edificio& edificio) {
	//No hago nada si colisiona un Edificio con un Bloque
} 


Bloque::~Bloque() { }
