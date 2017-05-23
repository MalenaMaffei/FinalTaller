#include "server_Armamento.h"

#define VEL_MOV 1

Armamento::Armamento(int id, int danio, Posicion &origen) : 
											id(id), danio(danio) {
	posiciones.push_back(origen);
}

void Armamento::atacarA(Objeto &atacado) {
	Posicion posAtacado;
	atacado.getPosicion(posAtacado);
	this->moverseA(posAtacado);
}


void Armamento::moverseA(Posicion &destino) {
	Posicion &actual = posiciones.back();  //todo CHEQUEAR SI DEVUELVE COPIA O REFERENCIA

	int xActual = actual.getX();
	int yActual = actual.getY();

	int xDestino = destino.getX();
	int yDestino = destino.getY();

	int difX = xDestino - xActual;
	int difY = yDestino - yActual;

	int modulo = sqrt(pow(difX, 2) + pow(difY, 2));

	int movEnX = (difX/modulo)*VEL_MOV;
	int movEnY = (difY/modulo)*VEL_MOV;

	while(xActual != xDestino && yActual != yDestino) {
		xActual += movEnX;
		yActual += movEnY;
		//todo
		//CHEQUEAR COLISIONES, OCUPAR NUEVA POSICION
		posiciones.push_back(siguiente);
	}
}

void Armamento::getPosiciones(std::vector<Posicion> &posRecorridas) {
	posRecorridas = posiciones;
}
