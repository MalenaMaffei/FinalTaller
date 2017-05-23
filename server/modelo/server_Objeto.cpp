#include "server_Objeto.h"

Objeto::Objeto(int id, int vida) : id(id), vida(vida) {}

bool Objeto::estaVivo() {
	return vida > 0;
}

void Objeto::recibirAtaque(int danio) {
	vida -= danio;
}
