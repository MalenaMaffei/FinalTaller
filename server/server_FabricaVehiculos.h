/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaVehiculos.h
 * Author: usuario
 *
 * Created on 30 de mayo de 2017, 11:14
 */

#ifndef FABRICAVEHICULOS_H
#define FABRICAVEHICULOS_H

#include "server_Vehiculo.h"
#include <map>

class FabricaVehiculos {
    public:
        static FabricaVehiculos* getInstancia();
        Vehiculo* getVehiculo(int tipo);
    private:
        static FabricaVehiculos* instancia;
        FabricaVehiculos();

        //Caracteristicas de vehiculo
        std::map<int,int> armamentos;
        std::map<int,double> frecuencias;
        std::map<int,int> alcances;
        std::map<int,int> vidas;
        std::map<int,int> velocidades;
        //Reqisitos de creación
        std::map<int,int> cantidades;
        std::map<int,time_t> tiempos;
        std::map<int,int> niveles;
};

#endif /* FABRICAVEHICULOS_H */

