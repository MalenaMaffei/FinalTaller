/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EdificioFabricaVehiculo.h
 * Author: usuario
 *
 * Created on 3 de junio de 2017, 21:37
 */

#ifndef EDIFICIOFABRICAVEHICULO_H
#define EDIFICIOFABRICAVEHICULO_H

#include "server_Edificio.h"

class EdificioFabricaVehiculo : Edificio {
public:
    EdificioFabricaVehiculo(int vida, double ancho, double alto, int idEquipo, 
                            int tipo);
    virtual ~EdificioFabricaVehiculo();
private:

};

#endif /* EDIFICIOFABRICAVEHICULO_H */

