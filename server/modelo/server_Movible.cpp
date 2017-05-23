#include "server_Movible.h"
#include "server_AEstrella.h"

Movible::Movible(int id, int vida, Posicion &pos, Armamento &armamento, int freqDisp, int alcance, 
														int velBase, int tiempoFabr, int nivelTec) : 
																Objeto(id, vida, pos), armamento(armamento) {}

void Movible::moverse(Posicion &origen, Posicion &destino) {
	AEstrella camino(origen, destino);
	std::vector<Posicion> recorrido;
	camino.getRecorrido(recorrido);
	for (size_t i = 0; i < recorrido.size(); i += velBase) {  //todo PREGUNTAR SI ESTA BIEN
		recorrido[i].ocupar(this); 
	}
}

bool Movible::mismoEquipo(Objeto &atacado) {
	//FALTA IMPLEMENTAR
}

bool Movible::estaAlAlcance(atacado) {
	Posicion posAtacado;
	atacado.getPos(posAtacado);
	int dist = pos.calcularDistancia(posAtacado);

	return dist <= alcance;
}

void Movible::atacarA(Objeto &atacado) {
	if (!this.mismoEquipo(atacado) && this.estaAlAlcance(atacado)) {
		armamento.atacarA(atacado);
	}
}

Movible::~Movible() {}
