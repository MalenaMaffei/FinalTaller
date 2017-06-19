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

	std::mutex m;
	std::condition_variable cond;
	
	Socket aceptor;
	
	int n = stoi(argv[2]);
	
	std::string port = argv[1];
	
	aceptor.setServerMode(port);
	
	std::vector<Jugador*> jugadores;
	
	std::vector<Socket> sockets;
	
	for (int i=0; i<n; i++) {
		Socket socket = aceptor.Accept ();
		jugadores.push_back(new Jugador(socket, colaDeRecibidos, i));
		sockets.push_back(socket);
	}
	
	Juego* juego = new Juego(colaDeRecibidos, &m, &cond, jugadores);

	juego->start();
	
	for (Jugador* jugador : jugadores) {
		jugador->start();
	}
	
	juego->join ();
	
	for (Jugador* jugador : jugadores) {
		jugador->join();
	}
	
	for (Jugador* jugador : jugadores) {
		delete jugador;
	}
	
	delete juego;
	
	return 0;
}

