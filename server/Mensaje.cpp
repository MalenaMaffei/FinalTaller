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
#include <sstream>
#include <string>
#include <array>
#include <iostream>

#define TODOS -1	//Si el mensaje estará destino a todos los clientes
#define ESCALA 100	//Al enviar las posiciones al cliente se envian con 
					//coordenadas enteras, para no perder totalmente la	
					//precisión se multiplican los double por 100.

enum largos {
	largoComando = 1,
	largoId = 3,
	largoX = 5,
	largoY = 5,
	largoDelCliente = 1,
	largoTipo = 2,
	largoColor = 1,
	largoEquipo = 1,
	largoVida = 3,
	largoConstrucciones = 2
};

enum comandos {
	comandoCrear = '0',
	comandoMatar = '1',
	comandoMover = '2',
	comandoDisparar = '3',
	comandoInfo = '4',
	comandoInfoUnidad = '4',
	comandoMapa = '5',
	comandoEquipo = '6',
	comandoInfoFabrica = '7',
	comandoDesconectar = '8'
};

std::string charToStr(char c) {
	std::stringstream ss;
	std::string s;
	ss<<c;
	ss>>s;
	return s;
}

//TODO cambiar nombre a agregarPadding
std::string agregarPadding2(int n, int len) {
	std::string nStr = std::to_string(n);
	int lenN = nStr.size();
	for (int i=0;i<(len-lenN);i++) {
		nStr.insert (0,"0");
	}  
	return nStr;
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
	std::string comando = charToStr(comandoCrear);
	std::array<double, 2> posicion = objeto->getPosicion();
	std::string x = agregarPadding2((int) (posicion[0]*ESCALA), largoX);
	std::string y = agregarPadding2((int) (posicion[1]*ESCALA), largoY);
	std::string tipo = agregarPadding2(objeto->getTipo (), largoTipo);
	std::string equipoStr = agregarPadding2(equipo, largoEquipo);
		
	this->mensaje = comando+id+x+y+tipo+equipoStr;	
	this->id = TODOS;
}

void Mensaje::mensajeDeMatar(std::string id) {
	std::string comando = charToStr(comandoMatar);
	this->mensaje = comando+id;
	this->id = TODOS;
}

void Mensaje::mensajeDeMover(Movible* movible, std::string id) {
	std::string comando = charToStr(comandoMover);
	std::array<double, 2> posicion = movible->getPosicion();
	std::string x = agregarPadding2((int) (posicion[0]*ESCALA), largoX);
	std::string y = agregarPadding2((int) (posicion[1]*ESCALA), largoY);
	
	this->mensaje = comando+id+x+y;
	this->id = TODOS;
}

void Mensaje::mensajeDeDisparar(std::string id, Objeto* objetivo) {
	std::string comando = charToStr(comandoDisparar);
	std::array<double,2> destino = objetivo->getPosicion();
	std::string x = agregarPadding2((int) (destino[0]*ESCALA), largoX);
	std::string y = agregarPadding2((int) (destino[1]*ESCALA), largoY);

	this->mensaje = comando+id+x+y;
	this->id = TODOS;
}

void Mensaje::mensajeDeInfoUnidad(Unidad* unidad, std::string id, int dst) {
	std::string comando = charToStr(comandoInfoUnidad);
	std::string tipo = agregarPadding2(unidad->getTipo(), largoTipo);
	std::string vida = agregarPadding2(unidad->getPorcentajeVida (), largoVida);
	
	this->mensaje = comando+id+tipo+vida;
	this->id = dst;
}

void Mensaje::mensajeDeInfoFabrica(Edificio* edificio, std::string id, 
									FabricaUnidades* fabricaUnidades,
									int dst) {
  
	std::string comando = charToStr(comandoInfoFabrica);
	std::string tipoStr = agregarPadding2(edificio->getTipo(), largoTipo);
	std::string vida = agregarPadding2(edificio->getPorcentajeVida (), 
										largoVida);

	int tipo = edificio->getTipo ();
	std::vector<int> unidadesPosibles;
	unidadesPosibles = fabricaUnidades->getUnidadesPosibles(tipo,
														 edificio->getNivel());
	
	std::string cantidad = agregarPadding2(unidadesPosibles.size(), 
											largoConstrucciones);

	std::string unidadesStr = "";
	
	for (int idActual : unidadesPosibles) {
		int tiempo = fabricaUnidades->getTiempo (idActual)/TICKS; //En segundos
		std::string tiempoStr = agregarPadding2(tiempo,4);
		std::string idStr = agregarPadding2(idActual,2);
		unidadesStr += idStr + tiempoStr;
	}

	int construyendo = (int) edificio->estaCreando ();
	std::string construyendoStr = std::to_string(construyendo);
	
	if (construyendo) {
		std::string tipoCreandoStr = agregarPadding2(edificio->getTipoCreando (), largoTipo);
		std::string porcentajeStr = agregarPadding2(edificio->getPorcentajeConstruccion (), largoVida);
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

std::string Mensaje::getMensaje() {
	return mensaje;
}

int Mensaje::getId() {
	return id;
}

Mensaje::~Mensaje () { }

