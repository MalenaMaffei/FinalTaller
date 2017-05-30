#include "server_Objeto.h"
#include <iostream>

Objeto::Objeto() : vida(0), ancho(0), alto(0) {}

Objeto::Objeto(int vida, double ancho, double alto) : vida(vida),
														ancho(ancho),
														alto(alto){}

bool Objeto::colisiona(Objeto& objeto) { 
	std::array<double,2> posicionOtro = objeto.posicion;
	double anchoOtro = objeto.ancho;
	double altoOtro = objeto.alto;
	
	double izquierdaOtro = posicionOtro[0];
	double derechaOtro = posicionOtro[0] + anchoOtro;
	double arribaOtro = posicionOtro[1];
	double abajoOtro = posicionOtro[1] + altoOtro;
	
	double izquierda = posicion[0];
	double derecha = posicion[0] + ancho;
	double arriba = posicion[1];
	double abajo = posicion[1] + alto;

	if (abajo <= arribaOtro)
		return false;
	if (arriba >= abajoOtro)
		return false;
	if (derecha <= izquierdaOtro)
		return false;
	if (izquierda >= derechaOtro)
		return false;
	return true;
}

std::array<double, 2> Objeto::getPosicion() {
	return posicion;
}

int Objeto::getVida() {
	return vida;
}

void Objeto::setPosicion (std::array<double,2> posicion) {
	this->posicion = posicion;
}

bool Objeto::recibirDanio(int danio) {
	std::cout<<"Hago daño: "<<danio<<std::endl;
	vida -= danio;
}

bool Objeto::estaVivo() {
	return (vida>0);
}


Objeto::~Objeto() { }