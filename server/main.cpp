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

using namespace std;

/*
 * 
 */
int
main (int argc, char** argv)
{
  
/*	Mapa mapa("mapa.map");
	
	AEstrella generadorDeCamino(mapa);	
	
	std::map <std::array<int,2>,std::array<int,2>> origenes;
	
	std::array<int,2> origen = {0,0};
	std::array<int,2> destino = {15,15};
	
	origenes = generadorDeCamino.getRecorrido (origen,destino);
		
	std::array<int,2> actual = destino;
	
	while (actual != origenes[actual]) {
		std::cout<<actual[0]<<","<<actual[1]<<std::endl;
		actual = origenes[actual];
	}*/
  
/*	std::array<double,2> origen = {0.0, 0.0};
	std::array<double,2> destino = {15.0, 15.0};

	Movible movible(100);	
	movible.setPosicion (destino);
	
	Armamento armamento;
	Municion municion = armamento.dispararA (origen, movible);
	
	std::array<double,2> pos = municion.getPosicion ();
	std::cout<<pos[0]<<","<<pos[1]<<std::endl;
	
	while (!municion.mover ()) {
		pos = municion.getPosicion ();
		std::cout<<pos[0]<<","<<pos[1]<<std::endl;		
	}*/
	
	Juego juego;
	
	juego.run ();
	
	return 0;
}

