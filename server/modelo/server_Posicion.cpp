#include "server_Posicion.h"

Posicion::Posicion(int x, int y) : x(x), y(y) {}

int Posicion::getX() {
	return x;
}

int Posicion::getY() {
	return y;
}

Posicion::~Posicion() {}

