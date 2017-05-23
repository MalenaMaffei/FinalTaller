#include "server_Movible.h"
#include "server_AEstrella.h"

Movible::Movible(int id, int vida, Armamento &armamento) : 
							Objeto(id, vida), armamento(armamento) {}

void Movible::moverse(Posicion &origen, Posicion &destino) {
	AEstrella camino(origen, destino);
	std::vector<Posicion> recorrido;
	camino.getRecorrido(recorrido);
	for (size_t i = 0; i < recorrido.size(); ++i) {
		recorrido[i].ocupar(this);
	}
}

Movible::~Movible() {}
