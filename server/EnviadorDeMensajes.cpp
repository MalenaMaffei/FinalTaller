/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnviadorDeMensajes.cpp
 * Author: usuario
 * 
 * Created on 19 de junio de 2017, 01:17
 */

#include "EnviadorDeMensajes.h"
#include "Mensaje.h"
#include "server_constants.h"
#include <chrono>
#include <time.h>

EnviadorDeMensajes::EnviadorDeMensajes(ColaMensajes& colaDeEnviados,
									   std::vector<Jugador*> jugadores) : 
											colaDeEnviados(colaDeEnviados),
											jugadores(jugadores) { }

void EnviadorDeMensajes::run() {
	while (true) {
		clock_t tiempo1 = clock();
		while (!colaDeEnviados.isEmpty ()) {
			Mensaje paquete = colaDeEnviados.desencolar ();
			int id = paquete.getId ();
			std::string mensaje = paquete.getMensaje ();
			for (Jugador* jugador : jugadores) {
				jugador->enviarMensaje (mensaje, id);
			}
		}	
		clock_t tiempo2 = clock();
		double intervaloDormir = CYCLE_TIME - 
									double(tiempo2 - tiempo1)/CLOCKS_PER_SEC;
		struct timespec req = {0};
		req.tv_sec = 0;
		req.tv_nsec = intervaloDormir*NANO;
		while (nanosleep(&req, &req) == -1); 

	}
}

EnviadorDeMensajes::~EnviadorDeMensajes () { }

