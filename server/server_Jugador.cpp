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

Jugador::Jugador (Socket& socket, ColaMensajes &colaDeRecibidos) : 
												socket(socket),
												colaDeRecibidos(colaDeRecibidos) { }

void Jugador::run () {
	while (1) {
		std::string mensaje = socket.ReceiveStrWLen ();
		colaDeRecibidos.encolar (mensaje);
	}
}

void Jugador::enviarMensaje(std::string& mensaje) {
	socket.SendStrWLen(mensaje);
}

Jugador::~Jugador () { }

