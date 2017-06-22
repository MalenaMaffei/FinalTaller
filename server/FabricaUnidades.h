/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaUnidades.h
 * Author: usuario
 *
 * Created on 21 de junio de 2017, 18:34
 */

#ifndef FABRICAUNIDADES_H
#define FABRICAUNIDADES_H

#include "server_FabricaRobots.h"
#include "server_FabricaVehiculos.h"

class FabricaUnidades {
public:
    FabricaUnidades();
    Unidad* getUnidad(int tipo);
    Robot* getRobot(int tipo);
    Vehiculo* getVehiculo(int tipo);
    int getCantidad(int tipo);
    int getTiempo(int tipo);
    double getAlcance(int tipo);
    std::vector<int> getUnidadesPosibles(int tipo, int nivel);

    virtual ~FabricaUnidades();
private:
    FabricaRobots fabricaRobots;
    FabricaVehiculos fabricaVehiculos;

};

#endif /* FABRICAUNIDADES_H */

