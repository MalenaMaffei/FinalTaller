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
#include <tinyxml2.h>

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

typedef enum {
	roca,
	puente,
	bandera,
	fuerte,
	fabricaRobot,
	fabricaVehiculo
} tipos;

//Intervalos de probabilidades de aparicion de cada terreno
double intervalos[8] = {0.5,	//TIERRA
						0.6,	//PRADERA
						0.65,	//NIEVE
						0.70,	//AGUA
						0.80,	//PANTANO
						0.82,	//LAVA
						0.91,	//CARRETERA
						1.0};	//CAMINO

//Probabilidad de repetición de un terreno
#define PROBA 0.99

#define H 200
#define W 200

GeneradorMapa::GeneradorMapa() { }

GeneradorMapa::~GeneradorMapa() { }

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
	
	std::default_random_engine generador(std::random_device{}());
	std::uniform_real_distribution<double> probabilidad(0.0,1.0);
	
	for (size_t i = 0; i<H; i++){
		for (size_t j = 0; j<W; j++){
			if (i == 0 && j == 0) {
				double proba = probabilidad(generador);
				mapa[i][j] = obtenerTerreno(proba);
			} else if (i == 0 && j != 0) {
				if (probabilidad(generador) < PROBA) {
					mapa[i][j] = mapa[i][j-1];
				} else {
					double proba = probabilidad(generador);
					mapa[i][j] = obtenerTerreno(proba);
				}
			} else if (i != 0 && j == 0) {
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

void GeneradorMapa::generarObjetos(const std::string& nombre) {
	
	int pasoX = W/NUM_CELDAS_X;
	int pasoY = H/NUM_CELDAS_Y;

	//Lleva noción de celdas ocupadas
	int celdas[NUM_CELDAS_X][NUM_CELDAS_Y] = {roca}; //Lleno mapa de rocas

	std::array<int,2> fuertes[4];
	std::array<int,2> fabricasR[4];
	std::array<int,2> fabricasV[4];
	std::array<int,2> banderas[NUM_BANDERAS];	
	
	//Ubica fuertes en las esquinas
	fuertes[0] = {pasoX/2, pasoY/2};
	celdas[fuertes[0][0]/pasoX][fuertes[0][1]/pasoY] = fuerte;

	fuertes[1] = {W - pasoX/2, pasoY/2};
	celdas[fuertes[1][0]/pasoX][fuertes[1][1]/pasoY] = fuerte;

	fuertes[2] = {W - pasoX/2, H - pasoY/2};
	celdas[fuertes[2][0]/pasoX][fuertes[2][1]/pasoY] = fuerte;

	fuertes[3] = {pasoX/2, H - pasoY/2};
	celdas[fuertes[3][0]/pasoX][fuertes[3][1]/pasoY] = fuerte;

	//Generadores random
	std::default_random_engine generador(std::random_device{}());
	std::uniform_int_distribution<int> posX(pasoX,W/2-pasoX);
	std::uniform_int_distribution<int> posY(pasoY,H/2-pasoY);
	
	//Ubica fabricas cercanas a fuertes del mismo equipo
	fabricasR[0] = {posX(generador), posY(generador)};
	celdas[fabricasR[0][0]/pasoX][fabricasR[0][1]/pasoY] = fabricaRobot;
	fabricasV[0] = {posX(generador), posY(generador)};
	//Que no queden las dos fabricas en la misma celda
	while (celdas[fabricasV[0][0]/pasoX][fabricasV[0][1]/pasoY]) {
		fabricasV[0] = {posX(generador), posY(generador)};
	}
	celdas[fabricasV[0][0]/pasoX][fabricasV[0][1]/pasoY] = fabricaVehiculo;
	
	fabricasR[1] = {W/2 + posX(generador), posY(generador)};
	celdas[fabricasR[1][0]/pasoX][fabricasR[1][1]/pasoY] = fabricaRobot;
	fabricasV[1] = {W/2 + posX(generador), posY(generador)};
	//Que no queden las dos fabricas en la misma celda
	while (celdas[fabricasV[1][0]/pasoX][fabricasV[1][1]/pasoY]) {
		fabricasV[1] = {W/2 + posX(generador), posY(generador)};
	}
	celdas[fabricasV[1][0]/pasoX][fabricasV[1][1]/pasoY] = fabricaVehiculo;
	

	fabricasR[2] = {W/2 + posX(generador), H/2 + posY(generador)};
	celdas[fabricasR[2][0]/pasoX][fabricasR[2][1]/pasoY] = fabricaRobot;
	fabricasV[2] = {W/2 + posX(generador), H/2 + posY(generador)};
	//Que no queden las dos fabricas en la misma celda
	while (celdas[fabricasV[2][0]/pasoX][fabricasV[2][1]/pasoY]) {
		fabricasV[2] = {W/2 + posX(generador), H/2 + posY(generador)};
	}
	celdas[fabricasV[2][0]/pasoX][fabricasV[2][1]/pasoY] = fabricaVehiculo;
	
	fabricasR[3] = {posX(generador), H/2 + posY(generador)};
	celdas[fabricasR[3][0]/pasoX][fabricasR[3][1]/pasoY] = fabricaRobot;
	fabricasV[3] = {posX(generador), H/2 + posY(generador)};
	//Que no queden las dos fabricas en la misma celda
	while (celdas[fabricasV[3][0]/pasoX][fabricasV[3][1]/pasoY]) {
		fabricasV[3] = {posX(generador), H/2 + posY(generador)};
	}
	celdas[fabricasV[3][0]/pasoX][fabricasV[3][1]/pasoY] = fabricaVehiculo;
	
	
	//Agrego banderas
	std::uniform_int_distribution<int> posBanderaX(pasoX,W-pasoX);
	std::uniform_int_distribution<int> posBanderaY(pasoY,H-pasoY);

	for (int i=0; i<NUM_BANDERAS; ++i) {
		banderas[i] = {posBanderaX(generador), posBanderaY(generador)};
		while (celdas[banderas[i][0]/pasoX][banderas[i][1]/pasoY]) {
			banderas[i] = {posBanderaX(generador), posBanderaY(generador)};
		}
		celdas[banderas[i][0]/pasoX][banderas[i][1]/pasoY] = bandera;
	}

	this->guardarConfiguracion(nombre,fuertes,fabricasR, 
							 fabricasV, banderas, celdas);
	//En el resto de las celdas van bloques centradas
}

void GeneradorMapa::guardarConfiguracion(const std::string& nombre, 
									    std::array<int,2> fuertes[NUM_EQUIPOS],
								        std::array<int,2> fabricasR[NUM_EQUIPOS],
							            std::array<int,2> fabricasV[NUM_EQUIPOS],
						                std::array<int,2> banderas[NUM_BANDERAS],
										int celdas[NUM_CELDAS_X][NUM_CELDAS_Y]) {
	
	int pasoX = W/NUM_CELDAS_X;
	int pasoY = H/NUM_CELDAS_Y;
  
	tinyxml2::XMLDocument xml;
	tinyxml2::XMLNode* rootXML = xml.NewElement("CONFIGURACION");

	//Agrego fuertes
	xml.InsertFirstChild(rootXML);
	tinyxml2::XMLElement* fuertesXML = xml.NewElement("FUERTES");
	for (int i = 0; i<NUM_EQUIPOS; ++i) {
		tinyxml2::XMLElement* fuerteXML = xml.NewElement("EDIFICIO");
		tinyxml2::XMLElement* equipo = xml.NewElement("EQUIPO");
		equipo->SetText(i);
		tinyxml2::XMLElement* x = xml.NewElement("X");
		x->SetText(fuertes[i][0]);
		tinyxml2::XMLElement* y = xml.NewElement("Y");
		y->SetText(fuertes[i][1]);
		fuerteXML->InsertEndChild(equipo);
		fuerteXML->InsertEndChild(x);
		fuerteXML->InsertEndChild(y);
		fuertesXML->InsertEndChild(fuerteXML);
	}
	rootXML->InsertEndChild(fuertesXML);

	//Agrego fabricas robots
	tinyxml2::XMLElement* fabricasRXML = xml.NewElement("FABRICAS_ROBOTS");
	for (int i = 0; i<NUM_EQUIPOS; ++i) {
		tinyxml2::XMLElement* fabricaXML = xml.NewElement("EDIFICIO");
		tinyxml2::XMLElement* equipo = xml.NewElement("EQUIPO");
		equipo->SetText(i);
		tinyxml2::XMLElement* x = xml.NewElement("X");
		x->SetText(fabricasR[i][0]);
		tinyxml2::XMLElement* y = xml.NewElement("Y");
		y->SetText(fabricasR[i][1]);
		fabricaXML->InsertEndChild(equipo);
		fabricaXML->InsertEndChild(x);
		fabricaXML->InsertEndChild(y);
		fabricasRXML->InsertEndChild(fabricaXML);
	}
	rootXML->InsertEndChild(fabricasRXML);

	//Agrego fabricas vehiculos
	tinyxml2::XMLElement* fabricasVXML = xml.NewElement("FABRICAS_VEHICULOS");
	for (int i = 0; i<NUM_EQUIPOS; ++i) {
		tinyxml2::XMLElement* fabricaXML = xml.NewElement("EDIFICIO");
		tinyxml2::XMLElement* equipo = xml.NewElement("EQUIPO");
		equipo->SetText(i);
		tinyxml2::XMLElement* x = xml.NewElement("X");
		x->SetText(fabricasV[i][0]);
		tinyxml2::XMLElement* y = xml.NewElement("Y");
		y->SetText(fabricasV[i][1]);
		fabricaXML->InsertEndChild(equipo);
		fabricaXML->InsertEndChild(x);
		fabricaXML->InsertEndChild(y);
		fabricasVXML->InsertEndChild(fabricaXML);
	}
	rootXML->InsertEndChild(fabricasVXML);
	
	//Agrego banderas
	tinyxml2::XMLElement* banderasXML = xml.NewElement("BANDERAS");
	for (int i = 0; i<NUM_BANDERAS; ++i) {
		tinyxml2::XMLElement* banderaXML = xml.NewElement("BANDERA");
		tinyxml2::XMLElement* x = xml.NewElement("X");
		x->SetText(banderas[i][0]);
		tinyxml2::XMLElement* y = xml.NewElement("Y");
		y->SetText(banderas[i][1]);
		banderaXML->InsertEndChild(x);
		banderaXML->InsertEndChild(y);
		banderasXML->InsertEndChild(banderaXML);
	}
	rootXML->InsertEndChild(banderasXML);
	
	//Lleno el resto de las celdas con bloques centrados
	tinyxml2::XMLElement* rocasXML = xml.NewElement("ROCAS");
	for (int i = 0; i<NUM_CELDAS_X; ++i) {
		for (int j = 0; j < NUM_CELDAS_Y; ++j) {
			if (celdas[i][j] != roca)
				continue;
			tinyxml2::XMLElement* rocaXML = xml.NewElement("ROCA");
			tinyxml2::XMLElement* x = xml.NewElement("X");
			x->SetText(pasoX/2 + pasoX*i);
			tinyxml2::XMLElement* y = xml.NewElement("Y");
			y->SetText(pasoY/2 + pasoY*j);
			rocaXML->InsertEndChild(x);
			rocaXML->InsertEndChild(y);
			rocasXML->InsertEndChild(rocaXML);	
		}
	}
	rootXML->InsertEndChild(rocasXML);
	
	xml.SaveFile(nombre.c_str());
}
