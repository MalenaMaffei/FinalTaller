/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: usuario
 *
 * Created on 29 de mayo de 2017, 10:00
 */

#ifndef JUEGO_H
#define JUEGO_H

#include "server_Mapa.h"
#include "server_Movible.h"
#include "server_Inmovible.h"
#include <vector>


class Juego {
public:
    Juego();
    void moverUnidades();
    void chequearColisiones();
    void eliminarMuertos();
    void run();
    virtual ~Juego();
private:
    Mapa mapa;
    //No puedo instanciar Movible porque es abstracto
    std::vector<Movible*> movibles; //Robots, vehiculos, balas
    std::vector<Inmovible*> inmovibles; //Bloques, puentes, banderas, edificios 

};

#endif /* JUEGO_H */

