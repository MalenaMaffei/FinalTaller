
#include "Bandera.h"
#include "Movible.h"
#include "Unidad.h"
#include "constantesServer.h"
#include <iostream>

Bandera::Bandera(double ancho, double alto, int tipo) : Inmovible(0, ancho, 
															alto, tipo), 
												idEquipo(SIN_EQUIPO), 
												idEquipoAnterior(SIN_EQUIPO){ }

void Bandera::setEquipo(int equipo) {
	idEquipo = equipo;
}

bool Bandera::estaVivo() {
	return true;
}

void Bandera::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Bandera::colisionar(Municion& municion) {
	//No hago nada si colisiona una Municion con una Bandera
}

void Bandera::colisionar(Unidad& personaje) {
	//Si colisiona una Unidad con una Bandera la Bandera cambia de equipo
	idEquipoAnterior = idEquipo;
	idEquipo = personaje.getEquipo();
}

void Bandera::colisionar(Bloque& bloque) {
	//No hago nada si colisiona Bloque con Bandera
}

void Bandera::colisionar(Bandera& bandera) {
	//No hago nada si colisiona Bandera con Bandera
}

void Bandera::colisionar(Edificio& edificio) {
	//No hago nada si colisiona Edificio con Bandera
}

int Bandera::getEquipo() {
	return idEquipo;
}

int Bandera::getEquipoAnterior() {
	return idEquipoAnterior;
}

Bandera::~Bandera() { }
