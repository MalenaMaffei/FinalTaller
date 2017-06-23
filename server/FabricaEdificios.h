/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaEdificios.h
 * Author: usuario
 *
 * Created on 23 de junio de 2017, 12:06
 */

#ifndef FABRICAEDIFICIOS_H
#define FABRICAEDIFICIOS_H

#include "server_Edificio.h"
#include <array>
#include <map>

class FabricaEdificios {
public:
    FabricaEdificios();
    Edificio* getEdificio(int tipo, int equipo, double x, double y, 
                            std::string id);
    virtual ~FabricaEdificios();
private:
    std::map<int,int> vidas;
    std::map<int,double> anchos;
    std::map<int,double> altos;
};

#endif /* FABRICAEDIFICIOS_H */

