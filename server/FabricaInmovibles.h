/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaInmovibles.h
 * Author: usuario
 *
 * Created on 24 de junio de 2017, 12:03
 */

#ifndef FABRICAINMOVIBLES_H
#define FABRICAINMOVIBLES_H

#include "server_Inmovible.h"
#include "server_Bloque.h"
#include "server_Bandera.h"
#include <map>
class FabricaInmovibles {
public:
    FabricaInmovibles();
    Inmovible* getInmovible(int tipo, double x, double y, std::string id);
    virtual ~FabricaInmovibles();
private:
    Bloque* getBloque(int tipo, double x, double y, std::string id);
    Bandera* getBandera(int tipo, double x, double y, std::string id);
    std::map<int,int> vidas;
    std::map<int,double> anchos;
    std::map<int,double> altos;
};

#endif /* FABRICAINMOVIBLES_H */

