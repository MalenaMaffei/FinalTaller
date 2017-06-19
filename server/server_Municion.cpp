/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Municion.cpp
 * Author: usuario
 * 
 * Created on 27 de mayo de 2017, 17:24
 */

#include "server_Municion.h"
#include "server_Unidad.h"
#include "server_Bloque.h"
#include <iostream>
#include <cmath>

#define DIFF 0.0000001

Municion::Municion (int vida, double ancho, double alto,
					int tipo, int danio, int velocidad) : 	
											Movible(vida, ancho, alto, velocidad, tipo),
											danio(danio),
											alcance(alcance) { 
	
}

Municion::Municion(const Municion& orig) : Movible(	orig.vida,
													orig.ancho,
													orig.alto,
													orig.trayectoria,
													orig.destino,
													orig.idEquipo,
													orig.velocidad,
													orig.objetivo,
													orig.distancia, 
													orig.tipo),
											danio (orig.danio) { }

Municion &Municion::operator=(Municion &orig) {
	objetivo = orig.objetivo;
	destino = orig.destino;
	trayectoria = orig.trayectoria;
	idEquipo = orig.idEquipo;
	vida = orig.vida;
	tipo = orig.tipo;
	danio = orig.danio;
	velocidad = orig.velocidad;
	distancia = orig.distancia;
	tipo = orig.tipo;
	alcance = orig.alcance;
	return *this;
}

Municion::Municion(Municion &&orig) : Movible(orig.vida, orig.ancho, orig.alto,
												orig.trayectoria,
												orig.destino,
												orig.idEquipo,
												orig.velocidad,							
												orig.objetivo,
												orig.distancia,
												orig.tipo),
										danio(orig.danio),
										alcance(orig.alcance) { }

Municion &Municion::operator=(Municion &&orig) {
	objetivo = orig.objetivo;
	destino = orig.destino;
	trayectoria = orig.trayectoria;
	idEquipo = orig.idEquipo;
	vida = orig.vida;
	tipo = orig.tipo;
	danio = orig.danio;
	velocidad = orig.velocidad;
	distancia = orig.distancia;
	tipo = orig.tipo;
	alcance = orig.alcance;
	return *this;
}

Municion::~Municion () { }

int Municion::getDanio () {
	return danio;
}

int Municion::getTipo () {
	return tipo;
}

bool Municion::mover (std::array<double,2> destino) {
	std::array<double, 2> direccion = { (destino[0] - this->posicion[0]),
										(destino[1] - this->posicion[1])};	
	double modulo = std::sqrt(direccion[0]*direccion[0] + direccion[1]*direccion[1]);
	direccion = {direccion[0]*alcance/modulo, direccion[1]*alcance/modulo};
	this->destino = {this->posicion[0]+direccion[0], this->posicion[1]+direccion[1]};
}

void Municion::colisionar(Municion& municion) {
	//Si colisionan las balas no pasa nada
}

void Municion::colisionar(Unidad& personaje) {
	//No colisiona con personajes del mismo equipo
	if (idEquipo == personaje.getEquipo ()) {
		return;
	}
	destino = posicion;
	vida -= danio;
	//Cuando colisiona, se resta también su danio, así se elimina luego
}

void Municion::colisionar(Bloque& bloque) {
	//Si colisiona con bloque se elimina la bala luego
	destino = posicion;
	vida -= danio;
}

void Municion::colisionar(Edificio& edificio) {
	//Si colisiona con un edificio se elimina la bala luego
	destino = posicion;
	vida -= danio;
}

void Municion::colisionar (Bandera& bandera) {
	//No hago nada si bandera colisiona con municion
}

void Municion::colisionar(Objeto& objeto) {
	objeto.colisionar (*this);
}

std::string Municion::puedeDisparar() {
	return std::string();
}

bool Municion::obtuvoBandera() {
	return false;
}

bool Municion::estaVivo() {
	return (vida>0 && posicion != destino);
}

void Municion::setAlcance(double alcance) {
	this->alcance = alcance;
}