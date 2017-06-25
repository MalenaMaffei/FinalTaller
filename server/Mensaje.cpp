/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.cpp
 * Author: usuario
 * 
 * Created on 18 de junio de 2017, 14:53
 */

#include "Mensaje.h"
#include "server_Jugador.h"
#include "server_constants.h"
#include "RellenadorDeNumeros.h"
#include <sstream>
#include <string>
#include <array>
#include <iostream>

std::string charToStr(char c) {
	std::stringstream ss;
	std::string s;
	ss<<c;
	ss>>s;
	return s;
}

Mensaje::Mensaje() { }

Mensaje::Mensaje(std::string mensaje, int id) : mensaje(mensaje), id(id) { }

void Mensaje::mensajeDeEquipo(Jugador* jugador) {
	std::string comando = charToStr(comandoEquipo);
	std::string equipo = std::to_string(jugador->getEquipo());
	this->mensaje = comando+equipo;
	this->id = jugador->getId();
}

void Mensaje::mensajeDeMapa(Mapa& mapa) {
	std::string comando = charToStr(comandoMapa);
	//No se envía el tamaño porque es convención
	std::string mapaStr = mapa.obtenerMensajeMapa ();
	this->mensaje = comando+mapaStr;
	this->id = TODOS;
}

void Mensaje::mensajeDeCrear(Objeto* objeto, std::string id, int equipo) {
	RellenadorDeNumeros rellenador;
	std::string comando = charToStr(comandoCrear);
	std::array<double, 2> posicion = objeto->getPosicion();
	std::string x = rellenador.rellenar((int) (posicion[0]*ESCALA), largoX);
	std::string y = rellenador.rellenar((int) (posicion[1]*ESCALA), largoY);
	std::string tipo = rellenador.rellenar(objeto->getTipo (), largoTipo);
	std::string equipoStr = rellenador.rellenar(equipo, largoEquipo);
		
	this->mensaje = comando+id+x+y+tipo+equipoStr;	
	this->id = TODOS;
}

void Mensaje::mensajeDeMatar(std::string id) {
	std::string comando = charToStr(comandoMatar);
	this->mensaje = comando+id;
	this->id = TODOS;
}

void Mensaje::mensajeDeMover(Movible* movible, std::string id) {
	RellenadorDeNumeros rellenador;
	std::string comando = charToStr(comandoMover);
	std::array<double, 2> posicion = movible->getPosicion();
	std::string x = rellenador.rellenar((int) (posicion[0]*ESCALA), largoX);
	std::string y = rellenador.rellenar((int) (posicion[1]*ESCALA), largoY);
	
	this->mensaje = comando+id+x+y;
	this->id = TODOS;
}

void Mensaje::mensajeDeDisparar(std::string id, Objeto* objetivo) {
	RellenadorDeNumeros rellenador;
	std::string comando = charToStr(comandoDisparar);
	std::array<double,2> destino = objetivo->getPosicion();
	std::string x = rellenador.rellenar((int) (destino[0]*ESCALA), largoX);
	std::string y = rellenador.rellenar((int) (destino[1]*ESCALA), largoY);

	this->mensaje = comando+id+x+y;
	this->id = TODOS;
}

void Mensaje::mensajeDeInfoUnidad(Unidad* unidad, std::string id, int dst) {
	RellenadorDeNumeros rellenador;
	std::string comando = charToStr(comandoInfoUnidad);
	std::string tipo = rellenador.rellenar(unidad->getTipo(), largoTipo);
	std::string vida = rellenador.rellenar(unidad->getPorcentajeVida (), largoVida);
	
	this->mensaje = comando+id+tipo+vida;
	this->id = dst;
}

void Mensaje::mensajeDeInfoFabrica(Edificio* edificio, std::string id, 
									FabricaUnidades* fabricaUnidades,
									int dst) {
  	RellenadorDeNumeros rellenador;
	std::string comando = charToStr(comandoInfoFabrica);
	std::string tipoStr = rellenador.rellenar(edificio->getTipo(), largoTipo);
	std::string vida = rellenador.rellenar(edificio->getPorcentajeVida (), 
										largoVida);

	int tipo = edificio->getTipo ();
	std::vector<int> unidadesPosibles;
	unidadesPosibles = fabricaUnidades->getUnidadesPosibles(tipo,
														 edificio->getNivel());
	
	std::string cantidad = rellenador.rellenar(unidadesPosibles.size(), 
											largoConstrucciones);

	std::string unidadesStr = "";
	
	for (int idActual : unidadesPosibles) {
		int tiempo = fabricaUnidades->getTiempo (idActual)/TICKS; //En segundos
		std::string tiempoStr = rellenador.rellenar(tiempo,4);
		std::string idStr = rellenador.rellenar(idActual,2);
		unidadesStr += idStr + tiempoStr;
	}

	int construyendo = (int) edificio->estaCreando ();
	std::string construyendoStr = std::to_string(construyendo);
	
	if (construyendo) {
		std::string tipoCreandoStr = rellenador.rellenar(edificio->getTipoCreando (), largoTipo);
		std::string porcentajeStr = rellenador.rellenar(edificio->getPorcentajeConstruccion (), largoVida);
		construyendoStr += tipoCreandoStr + porcentajeStr;
	}
	
	this->mensaje = comando + id + tipoStr + vida + cantidad + unidadesStr +
					construyendoStr;
	this->id = dst;
}

void Mensaje::mensajeDeSalir() {
	std::string comando = charToStr(comandoDesconectar);
	this->mensaje = comando;
	this->id = TODOS;
}

void Mensaje::mensajeDePerdedor(int id) {
	std::string comando = charToStr(comandoPerdedor);
	this->mensaje = comando;
	this->id = id;
}

std::string Mensaje::getMensaje() {
	return mensaje;
}

int Mensaje::getId() {
	return id;
}

Mensaje::~Mensaje () { }

