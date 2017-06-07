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
#include "server_AEstrella.h"
#include "server_Mapa.h"
#include "server_Movible.h"
#include "server_Objeto.h"
#include "server_FabricaMuniciones.h"
#include "server_Municion.h"
#include "server_Armamento.h"
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
	std::queue<std::string>* colaDeRecibidos = new std::queue<std::string> ();
	std::mutex m;
	std::condition_variable cond;
	
	Socket aceptor;
    Socket socket;
	
	aceptor.setServerMode("8080");
	socket = aceptor.Accept ();
  
	
	Juego* juego = new Juego(colaDeRecibidos, &m, &cond, &socket);
	
	juego->start();
	
	while (1) {
		std::string mensaje = socket.ReceiveStrWLen ();
		std::unique_lock<std::mutex> lk(m);
		colaDeRecibidos->push (mensaje);
		cond.notify_all ();
	}
		
	juego->join ();
	
	delete juego;
	
	return 0;
}

