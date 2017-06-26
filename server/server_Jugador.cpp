/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReceptorCliente.cpp
 * Author: usuario
 * 
 * Created on 13 de junio de 2017, 19:45
 */

#include "server_Jugador.h"
#include <iostream>
#include "common_SocketException.h"
#include "Logger.h"

Jugador::Jugador (Socket& socket, ColaMensajes &colaDeRecibidos, int id) : 
												socket(std::move(socket)),
												colaDeRecibidos(colaDeRecibidos),
												id(id) { }

void Jugador::run () {
	//TODO agregar bool salir
	salir.set_value(false);
	while (!salir.get_value()) {
		std::string mensaje;
		try {
			mensaje = socket.ReceiveStrWLen ();
		} catch (SocketException &e) {
			if (!salir.get_value()) { //Se salio desde el cliente
				Logger* logger = Logger::getInstancia();
				logger->logACout("Un cliente fue cerrado");
				logger->logACout("Todos los clientes serán desconectados");
				Mensaje mensajeSalir;
				mensajeSalir.mensajeDeSalir();
				colaDeRecibidos.encolar(mensajeSalir);
				this->finalizar();
			}
			// Si no, se salio del servidor
			continue;
		}
		Mensaje paquete(mensaje, id);
		colaDeRecibidos.encolar (paquete);
	}
}

void Jugador::enviarMensaje(std::string& mensaje, int id) {
	if (id != this->id && id != -1)
		return;
	try {
		socket.SendStrWLen(mensaje);
	} catch (SocketException &e) {
		throw e;
	}
}

int Jugador::getId() {
	return id;
}

void Jugador::setEquipo(int equipo) {
	this->equipo = equipo;
}

int Jugador::getEquipo() {
	return equipo;
}

void Jugador::finalizar() {
	if (salir.get_value()) {
		return;
	}
	salir.set_value(true);
}

Jugador::~Jugador () { }

