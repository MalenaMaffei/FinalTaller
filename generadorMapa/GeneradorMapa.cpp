/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneradorMapa.cpp
 * Author: usuario
 * 
 * Created on 21 de mayo de 2017, 12:47
 */

#include "GeneradorMapa.h"
#include <array>
#include <random>
#include <iostream>
#include <fstream>

typedef enum {
	TIERRA,
	PRADERA,
	NIEVE,
	AGUA,
	PANTANO,
	LAVA,
	CARRETERA,
	CAMINO
} territorios;

//Intervalos de probabilidades de aparicion
double intervalos[8] = {0.5,	//TIERRA
						0.6,	//PRADERA
						0.65,	//NIEVE
						0.70,	//AGUA
						0.80,	//PANTANO
						0.82,	//LAVA
						0.91,	//CARRETERA
						1.0};	//CAMINO

#define H 400
#define W 400
#define PROBA 0.99

GeneradorMapa::GeneradorMapa () { }

GeneradorMapa::~GeneradorMapa () { }

int obtenerTerreno(double probabilidad) {
	if (probabilidad<intervalos[TIERRA]) {
		return TIERRA;
	} else if (probabilidad<intervalos[PRADERA]) {
		return PRADERA;
	} else if (probabilidad<intervalos[NIEVE]) {
		return NIEVE;
	} else if (probabilidad<intervalos[AGUA]) {
		return AGUA;
	} else if (probabilidad<intervalos[PANTANO]) {
		return PANTANO;
	} else if (probabilidad<intervalos[LAVA]) {
		return LAVA;
	} else if (probabilidad<intervalos[CARRETERA]) {
		return CARRETERA;
	} else {
		return CAMINO;
	}
}

void GeneradorMapa::generarMapa(const std::string& nombre) {
	
	int mapa[H][W];
  
	std::ofstream myfile;
	
	myfile.open(nombre);
	
	std::default_random_engine generador (std::random_device{}());
	std::uniform_real_distribution<double> probabilidad(0.0,1.0);
	
	for (size_t i = 0; i<H; i++){
		for (size_t j = 0; j<W; j++){
			if (i == 0 && j == 0) {
				double proba = probabilidad(generador);
				mapa[i][j] = obtenerTerreno(proba);
			} else if (i == 0 & j != 0) {
				if (probabilidad(generador) < PROBA) {
					mapa[i][j] = mapa[i][j-1];
				} else {
					double proba = probabilidad(generador);
					mapa[i][j] = obtenerTerreno(proba);
				}
			} else if (i != 0 & j == 0) {
				if (probabilidad(generador) < PROBA) {
					mapa[i][j] = mapa[i-1][j];
				} else {
					double proba = probabilidad(generador);
					mapa[i][j] = obtenerTerreno(proba);
				}
			} else {
				if (probabilidad(generador) < PROBA) {
					if (probabilidad(generador) < 0.5) {
						mapa[i][j] = mapa[i-1][j];						
					} else {
						mapa[i][j] = mapa[i][j-1];
					}
				} else {
					double proba = probabilidad(generador);
					mapa[i][j] = obtenerTerreno(proba);
				}
			}
		}
	}
	for (size_t i = 0; i<H; i++) {
		for (size_t j = 0; j<W; j++) {
			myfile<<mapa[i][j]<<" ";
		}
		myfile<<std::endl;
	}
	
	myfile.close();
	
	return;
}
