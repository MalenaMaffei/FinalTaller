#include "server_Objeto.h"

Objeto::Objeto(int id, int vida, Posicion &pos) : id(id), vida(vida), pos(pos) {}

void Objeto::getPos(Posicion &resultado) {
	resultado = pos;
}

bool Objeto::estaVivo() {
	return vida > 0;
}

void Objeto::recibirAtaque(int danio) {
	vida -= danio;
}
