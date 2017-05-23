#include "server_Casillero.h"
#include <stdlib.h>

#define POSX 0
#define POSY 1
#define DIST_DIAG 14
#define DIST_ORT 10

Casillero::Casillero(std::vector<Casillero> &vecinos) : vecinos(vecinos), padre(NULL) {
	ocupado = false;
	distG = 0;
	distH = 0;
}

void Casillero::getVecinos(std::vector<Casillero> &resultado) {
	resultado = vecinos;
}

void Casillero::getPos(posicion &posCas) {
	posCas = posCentro;
}

bool Casillero::cmp(Casillero &other) {
	posicion otherCentro;
	other.getPos(otherCentro);
	return posCentro == otherCentro;
}

bool Casillero::estaOcupado() {
	return ocupado;
}

void Casillero::setG(int distancia) {
	distG = distancia;
}

int Casillero::getG() {
	return distG;
}

bool Casillero::estaEnDiagonal(posicion &destinoPos) {
	int x = std::get<POSX>(posCentro);
	int y = std::get<POSY>(posCentro);
	int destinoX = std::get<POSX>(destinoPos);
	int destinoY = std::get<POSY>(destinoPos);

	int distX = x - destinoX;
	int distY =	y - destinoY;

	if (distX == 0 || distY == 0) {
		return false;
	}
	return true;
}

int Casillero::getFactorTerreno() {
	return terreno.getFactor();
}

int Casillero::distanciaG(Casillero &destino) {
	int g;
	posicion destinoPos;
	destino.getPos(destinoPos);

	if (this->estaEnDiagonal(destinoPos)) {
		g = DIST_DIAG + (float(1)/destino.getFactorTerreno()); //FALTA DIFERENCIAR VEHICULOS DE ROBOTS
	} else {
		g = DIST_ORT + (float(1)/destino.getFactorTerreno()); //FALTA DIFERENCIAR VEHICULOS DE ROBOTS
	}

	return g;
}

void Casillero::setH(int distancia) {
	distH = distancia;
}

int Casillero::getH() {
	return distH;
}

int Casillero::distanciaH(Casillero &destino) {
	posicion destinoPos;
	destino.getPos(destinoPos);
	int x = std::get<POSX>(posCentro);
	int y = std::get<POSY>(posCentro);
	int destinoX = std::get<POSX>(destinoPos);
	int destinoY = std::get<POSY>(destinoPos);

	int h = 10*(abs(x-destinoX) + abs(y-destinoY));
	return h;
}

int Casillero::getF() {
	return distG + distH;
}

void Casillero::setPadre(Casillero &nuevoPadre) {
	padre = nuevoPadre;
}

void Casillero::getPadre(Casillero &resultado) {
	resultado = padre;
}

Casillero::~Casillero() {}

