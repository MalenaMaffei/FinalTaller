/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: usuario
 *
 * Created on 24 de mayo de 2017, 11:30
 */

#include <cstdlib>
#include "server_Jugador.h"
#include "server_AEstrella.h"
#include "server_Mapa.h"
#include "server_Movible.h"
#include "server_Objeto.h"
#include "server_FabricaMuniciones.h"
#include "server_Municion.h"
#include "server_Juego.h"
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <pthread.h>
#include <iostream>
#include "common_Socket.h"

using namespace std;

/*
 * 
 */
int
main (int argc, char** argv)
{	

	ColaMensajes colaDeRecibidos;
//	std::queue<std::string>* colaDeRecibidos = new std::queue<std::string> ();
	std::mutex m;
	std::condition_variable cond;
	
	Socket aceptor;
	
	aceptor.setServerMode("8080");
	
	std::vector<Jugador*> jugadores;
	
	std::vector<Socket> sockets;
	
	for (int i=0; i<2; i++) {
		Socket socket = aceptor.Accept ();
		jugadores.push_back(new Jugador(socket, colaDeRecibidos));
		sockets.push_back(socket);
	}
	
	Juego* juego = new Juego(colaDeRecibidos, &m, &cond, sockets);

	juego->start();
	
	for (Jugador* jugador : jugadores) {
		jugador->start();
	}
	
/*	while (1) {
		std::string mensaje = socket.ReceiveStrWLen ();
		std::unique_lock<std::mutex> lk(m);
		colaDeRecibidos->encolar (mensaje);
//		cond.notify_all ();
	}*/
		
	for (Jugador* jugador : jugadores) {
		jugador->join();
	}
	
	juego->join ();
	
	for (Jugador* jugador : jugadores) {
		delete jugador;
	}
	
	delete juego;
	
	return 0;
}

