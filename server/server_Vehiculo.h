/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: usuario
 *
 * Created on 30 de mayo de 2017, 00:03
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include "server_Unidad.h"

class Robot;

class Vehiculo : public Unidad {
public:
    Vehiculo(int vida, double ancho, double alto, 
            int frecuenciaDisparo, int alcance, 
            int velocidad, int tipo, int armamento);
    
    bool addConductor(Robot* conductor);
    virtual ~Vehiculo();
private:
    Robot* conductor;
};

#endif /* VEHICULO_H */

