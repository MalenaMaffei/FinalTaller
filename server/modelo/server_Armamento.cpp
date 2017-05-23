#include "server_Armamento.h"

Armamento::Armamento(int danio, Posicion &origen) : danio(danio), origen(origen) {}

void Armamento::atacarA(Objeto &atacado) {
	Posicion posAtacado;
	atacado.getPosicion(posAtacado);
	this->moverseA(posAtacado);
}


void Armamento::moverseA(Posicion &destino) {

}