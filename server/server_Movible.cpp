#include "server_Movible.h"
#include <math.h>
#include <iostream>

#define DIFF 0.0000001


bool esPosicionIntermedia(std::array<double,2> a,
						  std::array<double,2> b,
						  std::array<double,2> c) {
  
	//Chequeo si puntos estan alineados
	double crossproduct = (c[1]-a[1])*(b[0]-a[0]) - (c[0]-a[0])*(b[1]-a[1]);
	if (abs(crossproduct)>DIFF) return false;
	
	//Verifico que c este entre a y b
	double dotproduct = (c[0]-a[0])*(b[0]-a[0]) + (c[1]-a[1])*(b[1]-a[1]);
	if (dotproduct<0) return false;
	
	double squaredlengthba = (b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1]);
	if (dotproduct > squaredlengthba) return false;
	
	return true;
}

Movible::Movible(int vida, double ancho, double alto) :	Objeto(vida, 
															ancho, 
															alto) {}

Movible::Movible (int vida, double ancho, double alto, 
					std::vector<std::array<int,2>> trayectoria,
					std::array<double,2> destino, int idEquipo) : Objeto(vida, 
																		ancho, 
																		alto), 
															trayectoria(trayectoria),
															destino(destino),
															idEquipo(idEquipo) { }

Movible::Movible(const Movible& orig) : Objeto(orig.vida, orig.ancho, 
											   orig.alto), 
										idEquipo(orig.idEquipo) { }

Movible& Movible::operator=(const Movible& orig) {
	vida = orig.vida;
	ancho = orig.ancho;
	alto = orig.alto;
	idEquipo = orig.idEquipo;
	return *this;
}


bool Movible::mover (std::array<double,2> destino) {
	this->destino = destino;
	return true;
//	return mover();
}

void Movible::setPosicion(std::array<double,2> posicion) {
	Objeto::setPosicion (posicion);
	posicionAnterior = posicion;
	destino = posicion;
}

bool Movible::mover () {
	std::array<double, 2> direccion = { (destino[0] - posicion[0]),
										(destino[1] - posicion[1])};	
	
	float modulo = sqrt(direccion[0]*direccion[0] + direccion[1]*direccion[1]);
	
	if (abs(modulo) < DIFF)
		return true;
	
	direccion = {direccion[0]/modulo, direccion[1]/modulo};
	
	//Se mueve de a una unidad, debería haber un diferencial
	//TODO
	
	posicionAnterior = posicion;
	posicion = {posicion[0] + direccion[0], posicion[1] + direccion[1]};

	std::array<double,2> siguiente = {posicion[0] + direccion[0], 
										posicion[1] + direccion[1]};
	
	if (esPosicionIntermedia(posicion,siguiente,destino)) {
		posicion = destino;
		return true;
	}
	
	return false;
}

bool Movible::retroceder() {
	posicion = posicionAnterior;	//Se utiliza en caso de colision
	return true;
}

int Movible::getEquipo() {
	return idEquipo;
}

void Movible::setEquipo(int idEquipo) {
	this->idEquipo = idEquipo;
	
}

Movible::~Movible() { }