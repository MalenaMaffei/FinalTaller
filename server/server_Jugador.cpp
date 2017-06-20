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

//TODO Move semantics
//Implementar constructor por movimiento en socket
//Agregar close en destructor de socket
//Pasar por movimiento
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
				std::cout<<"Un cliente fue cerrado"<<std::endl;
				std::cout<<"Todos los clientes serán desconectados"<<std::endl;
				mensaje = "8";
				Mensaje paquete(mensaje, -1);
				colaDeRecibidos.encolar(paquete);
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

void Jugador::finalizar() {
	if (salir.get_value()) {
		return;
	}
	salir.set_value(true);
	socket.Shutdown(SHUT_RDWR);
}

Jugador::~Jugador () { }

