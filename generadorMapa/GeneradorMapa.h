/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneradorMapa.h
 * Author: usuario
 *
 * Created on 21 de mayo de 2017, 12:47
 */

#ifndef GENERADORMAPA_H
#define GENERADORMAPA_H

#include <array>

#define NUM_EQUIPOS 4

//Se divide el tablero en celdas para agregar bloques, fabricas y banderas
#define NUM_CELDAS_X 8
#define NUM_CELDAS_Y 8

//Numero de banderas a colocar aleatoriamente en el tablero
#define NUM_BANDERAS 12

class GeneradorMapa {
public:
    GeneradorMapa();
    void generarMapa();
    void generarMapa(const std::string& nombre);
    void generarObjetos(const std::string& nombre);
    virtual ~GeneradorMapa();
private:
    void guardarConfiguracion(const std::string& nombre, 
                                std::array<int,2> fuertes[NUM_EQUIPOS],
                                std::array<int,2> fabricasR[NUM_EQUIPOS],
                                std::array<int,2> fabricasV[NUM_EQUIPOS],
                                std::array<int,2> banderas[NUM_BANDERAS],
                                int celdas[NUM_CELDAS_X][NUM_CELDAS_Y]);
};
#endif /* GENERADORMAPA_H */

