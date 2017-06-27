
#include "server_Unidad.h"
#include <iostream>

Unidad::Unidad (int vida, double ancho, double alto, 
					int frecuenciaDisparo, int alcance, 
					int velocidad, int tipo, int armamento) : 
										Movible(vida, ancho, alto, velocidad, 
											 tipo),
										frecuenciaDisparo(frecuenciaDisparo),
										alcance(alcance),
										estado(REPOSO),
										tiempoADisparo(0),
										bandera(std::string()), 
										armamento(armamento) { }

void Unidad::dispararA(std::string objetivo) {
	this->objetivo = objetivo;
	estado = DISPARAR;
}

Unidad::~Unidad () { }

void Unidad::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Unidad::colisionar(Municion& municion) {
	if (idEquipo == municion.getEquipo ()) {
		return;
	}
	this->recibirDanio(municion.getDanio ());
}

void Unidad::colisionar(Unidad& personaje) {
	if (this->idEquipo == personaje.idEquipo) 
		return;
	this->retroceder ();
	destino = posicion; //Si colisiono con otro personaje me quedo quieto
	//En un futuro podría recalcular camino a destino
}

void Unidad::colisionar(Bloque& bloque) {
	this->retroceder ();
	destino = posicion;
}

void Unidad::colisionar(Edificio& edificio) {
	this->retroceder ();
	destino = posicion;
}

void Unidad::colisionar(Bandera& bandera) {
//	std::cout<<"colisiono con bandera"<<std::endl;
	std::cout<<bandera.getEquipo()<<std::endl;
	std::cout<<idEquipo<<std::endl;
	if (bandera.getEquipo() != idEquipo) {
//		std::cout<<"capturo bandera"<<std::endl;
		this->bandera = bandera.getId();
	}
}


std::string Unidad::puedeDisparar () {
	if (estado == DISPARAR && tiempoADisparo == 0 && !objetivo.empty()) {
		tiempoADisparo = frecuenciaDisparo;
		return objetivo;
	}
	if (tiempoADisparo)
		tiempoADisparo--;
	return std::string();	//empty string
}

bool Unidad::obtuvoBandera () {
	if (!bandera.empty()) {
		return true;
	}
	return false;
}

std::string Unidad::getBandera() {
	std::string banderaAux = bandera;
	bandera = std::string();
	return banderaAux;
}

int Unidad::getArmamento () {
	return armamento;
}
