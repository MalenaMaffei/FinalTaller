#include "server_Posicion.h"
#include <stdlib.h>

#define POSX 0
#define POSY 1
#define DIST_DIAG 14
#define DIST_ORT 10

Posicion::Posicion(Terreno &terreno, unsigned int x, unsigned int y) : 
							terreno(terreno), x(x), y(y), ocupante(NULL), vecinos(NULL), padre(NULL) {
	distG = 0;
	distH = 0;
}

unsigned int Posicion::getX() {
	return x;
}

unsigned int Posicion::getY() {
	return y;
}

int Posicion::calcularDistancia(Posicion &other) {
	int x = pos.getX();
	int y = pos.getY();

	int xOther = other.getX();
	int yOther = other.getY();

	int difX = xOther - x;
	int difY = yOther - y;

	int dist = sqrt(pow(difX, 2) + pow(difY, 2));
	return dist;
}

void Posicion::setVecinos(std::vector<Posicion> &nuevosVecinos) {
	vecinos = nuevosVecinos;
}

void Posicion::getVecinos(std::vector<Posicion> &resultado) {
	resultado = vecinos;
}

bool Posicion::cmp(Posicion &other) {
	int otherX = other.getX();
	int otherY = other.geY();
	return (x == otherX && y == otherY);
}

void Posicion::ocupar(Objeto &nuevoOcupante) {
	ocupante = nuevoOcupante;
}

bool Posicion::estaOcupado() {
	return ocupante != NULL;
}

void Posicion::setG(int distancia) {
	distG = distancia;
}

int Posicion::getG() {
	return distG;
}

bool Posicion::estaEnDiagonal(Posicion &destinoPos) {
	int destinoX = destinoPos.getX();
	int destinoY = destinoPos.getY();

	int distX = x - destinoX;
	int distY =	y - destinoY;

	if (distX == 0 || distY == 0) {
		return false;
	}
	return true;
}

int Posicion::getFactorTerreno() {
	return terreno.getFactor();
}

int Posicion::distanciaG(Posicion &destino) {
	int g;
	posicion destinoPos;
	destino.getPos(destinoPos);

	if (this->estaEnDiagonal(destinoPos)) {
		g = DIST_DIAG + (float(10)/destino.getFactorTerreno()); //FALTA DIFERENCIAR VEHICULOS DE ROBOTS
	} else {
		g = DIST_ORT + (float(10)/destino.getFactorTerreno()); //FALTA DIFERENCIAR VEHICULOS DE ROBOTS
	}

	return g;
}

void Posicion::setH(int distancia) {
	distH = distancia;
}

int Posicion::getH() {
	return distH;
}

int Posicion::distanciaH(Posicion &destino) {
	posicion destinoPos;
	destino.getPos(destinoPos);

	int destinoX = destinoPos.getX();
	int destinoY = destinoPos.getY();

	int h = 10*(abs(x-destinoX) + abs(y-destinoY));
	return h;
}

int Posicion::getF() {
	return distG + distH;
}

void Posicion::setPadre(Posicion &nuevoPadre) {
	padre = nuevoPadre;
}

void Posicion::getPadre(Posicion &resultado) {
	resultado = padre;
}

Posicion::~Posicion() {}

