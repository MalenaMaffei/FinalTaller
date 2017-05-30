/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaRobots.h
 * Author: usuario
 *
 * Created on 30 de mayo de 2017, 10:02
 */

#ifndef FABRICAROBOTS_H
#define FABRICAROBOTS_H

#include <map>
#include <time.h>
#include "server_Robot.h"

class FabricaRobots {
public:
    static FabricaRobots* getInstancia();
    Robot* getRobot(int tipo);
private:
    static FabricaRobots* instancia;
    FabricaRobots();
    
    //Caracteristicas de robot
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

#endif /* FABRICAROBOTS_H */

