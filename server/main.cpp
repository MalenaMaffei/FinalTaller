
#include <cstdlib>
#include "Logger.h"
#include "Jugador.h"
#include "AEstrella.h"
#include "Mapa.h"
#include "Movible.h"
#include "Objeto.h"
#include "FabricaMuniciones.h"
#include "Municion.h"
#include "Juego.h"
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <pthread.h>
#include <iostream>
#include "common_Socket.h"
#include "Logger.h"
#include <string>
#include <vector>

using namespace std;

/* Función main donde se crean los Jugadores y el Juego, y se inician y esperan
 * los hilos.
 * Es el Thread principal y espera una 'q' en stdin para cerrar el servidor.
 */
int
main(int argc, char** argv)
{	
	if (argc != 3) {
		Logger* logger = Logger::getInstancia();
		logger->logACout("Iniciar el server con: ");
		logger->logACout("./server <puerto> <#clientes>");
		logger->logACout("Intentelo nuevamente");
		return -1;
	}

	ColaMensajes colaDeRecibidos;

	Socket aceptor;
	
	int n = stoi(argv[2]);
	
	std::string port = argv[1];
	
	aceptor.setServerMode(port);
	
	std::vector<Jugador*> jugadores;
	
	for (int i=0; i<n; i++) {
		Socket socket = aceptor.Accept();
		jugadores.push_back(new Jugador(socket, colaDeRecibidos, i));
	}
	
	Juego* juego = new Juego(colaDeRecibidos, jugadores);

	juego->start();
		
	for (Jugador* jugador : jugadores) {
		jugador->start();
	}

	std::string salir;
	while (salir != "q") {
		std::cin>>salir;
	}
	
	if (!juego->hayGanador()) {
		juego->finalizar();
	}
	
	juego->join();
	
	delete juego;
	
	for (Jugador* jugador : jugadores) {
		jugador->join();
	}
	
	for (Jugador* jugador : jugadores) {
		delete jugador;
	}
	
	Logger::deleteInstancia();
	
	return 0;
}

