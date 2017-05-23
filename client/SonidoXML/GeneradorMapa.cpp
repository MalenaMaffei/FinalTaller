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

#define H 500
#define W 500
#define PROBA 0.99

GeneradorMapa::GeneradorMapa () { }

GeneradorMapa::~GeneradorMapa () { }

void GeneradorMapa::generarMapa() {
	
	int mapa[H][W];
  
	std::ofstream myfile;
	
	myfile.open("mapa.map");
	
	std::default_random_engine generador (std::random_device{}());
	std::uniform_int_distribution<int> distribucion_terrenos(0,7);
	std::uniform_real_distribution<double> probabilidad(0.0,1.0);
	
	for (size_t i = 0; i<H; i++){
		for (size_t j = 0; j<W; j++){
			if (i == 0 && j == 0) {
				mapa[0][0] = distribucion_terrenos(generador);
			} else if (i == 0 & j != 0) {
				if (probabilidad(generador) < PROBA) {
					mapa[i][j] = mapa[i][j-1];
				} else {
					mapa[i][j] = distribucion_terrenos(generador);					
				}
			} else if (i != 0 & j == 0) {
				if (probabilidad(generador) < PROBA) {
					mapa[i][j] = mapa[i-1][j];
				} else {
					mapa[i][j] = distribucion_terrenos(generador);					
				}
			} else {
				if (probabilidad(generador) < PROBA) {
					if (probabilidad(generador) < 0.5) {
						mapa[i][j] = mapa[i-1][j];						
					} else {
						mapa[i][j] = mapa[i][j-1];
					}
				} else {
					mapa[i][j] = distribucion_terrenos(generador);					
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
