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

Jugador::Jugador (Socket& socket, ColaMensajes &colaDeRecibidos, int id) : 
												socket(socket),
												colaDeRecibidos(colaDeRecibidos),
												id(id) { }

void Jugador::run () {
	while (1) {
		std::string mensaje = socket.ReceiveStrWLen ();
		Mensaje paquete(mensaje, id);
		colaDeRecibidos.encolar (paquete);
	}
}

void Jugador::enviarMensaje(std::string& mensaje, int id) {
	std::cout<<"Mensaje: "<<mensaje<<std::endl;
	std::cout<<"Id mensaje: "<<id<<std::endl;
	std::cout<<"Id jugador: "<<this->id<<std::endl;
	if (id != this->id && id != -1)
		return;
	std::cout<<"envio mensaje"<<std::endl;
	socket.SendStrWLen(mensaje);
}

int Jugador::getId() {
	return id;
}

Jugador::~Jugador () { }

