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
	while (1) {
		std::string mensaje = socket.ReceiveStrWLen ();
		//Try/Catch
		Mensaje paquete(mensaje, id);
		colaDeRecibidos.encolar (paquete);
	}
}

void Jugador::enviarMensaje(std::string& mensaje, int id) {
	if (id != this->id && id != -1)
		return;
	socket.SendStrWLen(mensaje);
}

int Jugador::getId() {
	return id;
}

Jugador::~Jugador () { }

