/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terreno.h
 * Author: usuario
 *
 * Created on 23 de mayo de 2017, 16:17
 */

#ifndef TERRENO_H
#define TERRENO_H

class Terreno {
public:
    Terreno(int tipo, double velocidadRobots, double velocidadVehiculos);
    Terreno(const Terreno& orig);
    Terreno(Terreno &&orig);
    Terreno& operator=(const Terreno& orig);
    double getFactor();
    int getTipo();
    Terreno &operator=(Terreno &&orig);
    virtual ~Terreno();
private:
    double velocidadRobots;
    double velocidadVehiculos;
    int tipo;
};

#endif /* TERRENO_H */

