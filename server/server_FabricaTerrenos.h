/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaTerreno.h
 * Author: usuario
 *
 * Created on 23 de mayo de 2017, 16:35
 */

#ifndef FABRICATERRENOS_H
#define FABRICATERRENOS_H

#include <map>
#include "server_Terreno.h"

class FabricaTerrenos {
public:
    FabricaTerrenos();
    Terreno getTerreno(int tipo);
    virtual ~FabricaTerrenos();
private:
    std::map<int, int> velocidadesVehiculos;
    std::map<int, int> velocidadesRobots;
};

#endif /* FABRICATERRENOS_H */

