/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.h
 * Author: usuario
 *
 * Created on 18 de junio de 2017, 14:53
 */

#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>
#include "server_Mapa.h"
#include "server_Objeto.h"
#include "server_Movible.h"
#include "server_Unidad.h"
#include "FabricaUnidades.h"
#include <array>
#include <vector>

class Jugador;

class Mensaje {
public:
    Mensaje();
    Mensaje(std::string mensaje, int id);
    void mensajeDeEquipo(Jugador* jugador);
    void mensajeDeMapa(Mapa& mapa);
    void mensajeDeCrear(Objeto* objeto, std::string id, int equipo);
    void mensajeDeMatar(std::string id);
    void mensajeDeMover(Movible* movible, std::string id);
    void mensajeDeDisparar(std::string id, Objeto* objetivo);
    void mensajeDeInfoUnidad(Unidad* unidad, std::string id, int dst);
    void mensajeDeInfoFabrica(Edificio* edificio, std::string id, 
                                FabricaUnidades* fabricaUnidades,
                                int dst);
    std::string getMensaje();
    int getId();
    virtual ~Mensaje();
private:
    std::string mensaje;
    int id;
};

#endif /* MENSAJE_H */

