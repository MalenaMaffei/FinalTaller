/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManejadorIDs.h
 * Author: usuario
 *
 * Created on 24 de junio de 2017, 13:19
 */

#ifndef MANEJADORIDS_H
#define MANEJADORIDS_H

#include <string>
#include "RellenadorDeNumeros.h"

class ManejadorIDs {
public:
    ManejadorIDs();
    std::string getIDMunicion();
    std::string getIDEdificio();
    std::string getIDMovible();
    std::string getIDInmovible();
    virtual ~ManejadorIDs();
private:
    RellenadorDeNumeros rellenador;
    int proximoIDMovible;
    int proximoIDEdificio;
    int proximoIDInmovible;
    int proximoIDMunicion;
};

#endif /* MANEJADORIDS_H */

