
#include "Edificio.h"
#include "Unidad.h"
#include "Bloque.h"
#include "Municion.h"
#include "Bandera.h"
#include <iostream>
#include <cmath>

Edificio::Edificio(int vida, double ancho, double alto, 
					int equipo, int tipo) :	
									Inmovible(vida,ancho,
											alto, tipo),
									equipo(equipo), 
									tipoCreando(-1),
									construccionesRealizadas(0),
									nivel(1) { }

void Edificio::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Edificio::colisionar(Municion& municion) {
	this->recibirDanio(municion.getDanio());
}	

void Edificio::colisionar(Unidad& personaje) {
	//No hago nada si colisiona una Unidad con un Edificio
}

void Edificio::colisionar(Bloque& bloque) {
	//No hago nada si colisiona un Bloque con un Edificio
}

void Edificio::colisionar(Edificio& edificio) {
	//No hago nada si colisiona un Edificio con un Edificio
}

void Edificio::colisionar(Bandera& bandera) {
	//No hago nada si colisiona una Bandera con un Edificio
}

void Edificio::setFabricacion(int tiempoBase, int territorios, int tipo) {
	this->tiempoFabricacion = (double(tiempoBase)/double(territorios))/
								std::sqrt(double(vida)/double(vidaTotal));
	this->tiempoParaFabricacion = this->tiempoFabricacion;
	this->tipoCreando = tipo;
}

Edificio::~Edificio() { }

int Edificio::debeCrear() {
	if (tipoCreando == -1) 
		return -1;
  	if (tiempoParaFabricacion == 0) {
		tiempoParaFabricacion = tiempoFabricacion;
		++construccionesRealizadas;
		int aux = tipoCreando;
		tipoCreando = -1; //Hago que cree de a uno
		if (construccionesRealizadas%2) {
			++nivel;
		}
		return aux; //Devuelvo tipo a crear
	}
	if (tiempoParaFabricacion)
		tiempoParaFabricacion--;
	return -1;
}

int Edificio::getNivel() {
	return nivel;
}

bool Edificio::estaCreando() {
	return tipoCreando!=-1; //Si esta en -1 no esta creando nada
}

void Edificio::setEquipo(int equipo) {
	this->equipo = equipo;
}

int Edificio::getEquipo() {
	return equipo;
}

int Edificio::getPorcentajeConstruccion() {
	return double(tiempoFabricacion-tiempoParaFabricacion)/
												double(tiempoFabricacion)*100;
}

int Edificio::getTiempoParaFabricacion(int tiempoBase, int territorios) {
	return (double(tiempoBase)/double(territorios))/
								std::sqrt(double(vida)/double(vidaTotal));
}

int Edificio::getTipoCreando() {
	return tipoCreando;
}
