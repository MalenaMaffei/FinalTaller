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

#ifndef FABRICATERRENO_H
#define FABRICATERRENO_H

#include <map>

class FabricaTerreno {
public:
    FabricaTerreno();
    FabricaTerreno(const FabricaTerreno& orig);
    virtual ~FabricaTerreno();
private:
    std::map<int, int> factores;
};

#endif /* FABRICATERRENO_H */

