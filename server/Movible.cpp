#include "Movible.h"
#include <cmath>
#include <iostream>
#include "constantesServer.h"
#include <string>
#include <algorithm>
#include <vector>

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

Movible::Movible(int vida, double ancho, double alto, int velocidad, int tipo):	
														Objeto(vida, ancho, 
														alto, tipo),
														velocidad(velocidad),
														objetivo(""),
														distancia(0){}

Movible::Movible(int vida, double ancho, double alto, 
					std::vector<std::array<double,2>> trayectoria,
					std::array<double,2> destino, 
					int idEquipo, int velocidad, std::string objetivo,
					double distancia, int tipo) : 
										Objeto(vida, ancho, alto, tipo), 
										trayectoria(trayectoria),
										destino(destino),
										velocidad(velocidad),
										objetivo(objetivo), 
										idEquipo(idEquipo), 
										distancia(distancia) { }

Movible::Movible(const Movible& orig) : Objeto(orig.vida, orig.ancho, 
											   orig.alto, orig.tipo), 
										velocidad(orig.velocidad),
										objetivo(orig.objetivo),
										idEquipo(orig.idEquipo),
										distancia(orig.distancia){ }

Movible& Movible::operator=(const Movible& orig) {
	vida = orig.vida;
	ancho = orig.ancho;
	alto = orig.alto;
	idEquipo = orig.idEquipo;
	velocidad = orig.velocidad;
	objetivo = orig.objetivo;
	distancia = orig.distancia;
	tipo = orig.tipo;
	return *this;
}


void Movible::mover(std::array<double,2> destino) {
	this->destino = destino;
}

void Movible::setPosicion(std::array<double,2> posicion) {
	Objeto::setPosicion(posicion);
	posicionAnterior = posicion;
	destino = posicion;
}

bool Movible::mover(double factorTerreno) {
	std::array<double, 2> direccion = { (destino[0] - posicion[0]),
										(destino[1] - posicion[1])};	
	
	double modulo = std::sqrt(direccion[0]*direccion[0] + 
								direccion[1]*direccion[1]);
	
	if (std::abs(modulo) < DIFF) {
		posicion = destino;
		if (!trayectoria.empty()) {
			destino = trayectoria.back();
			trayectoria.pop_back();
		}
		return false;
	}
	
	int velFinal = std::max(this->calcularVelocidad(factorTerreno),1);
		
	direccion = {direccion[0]/modulo, direccion[1]/modulo};

	posicionAnterior = posicion;
	posicion = {posicion[0] + direccion[0]*velFinal*CYCLE_TIME, 
				posicion[1] + direccion[1]*velFinal*CYCLE_TIME};


	std::array<double,2> siguiente = {posicion[0] + 
										direccion[0]*velFinal*CYCLE_TIME, 
										posicion[1] + 
										direccion[1]*velFinal*CYCLE_TIME};
	
	if (esPosicionIntermedia(posicion,siguiente,destino)) {
		posicion = destino;
		return true;
	}
	
	distancia += velFinal*CYCLE_TIME;
	
	return true;
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

void Movible::setObjetivo(std::string objetivo) {
	this->objetivo = objetivo;
}

void Movible::setTrayectoria(std::vector< std::array<double,2> > trayectoria) {
	this->trayectoria = trayectoria;
	if (!trayectoria.empty()) {
		this->mover(trayectoria.back());
		this->trayectoria.pop_back();
	}
}


Movible::~Movible() { }
