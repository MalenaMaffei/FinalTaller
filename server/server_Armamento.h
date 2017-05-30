/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armamento.h
 * Author: usuario
 *
 * Created on 27 de mayo de 2017, 16:55
 */

#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include "server_Objeto.h"
#include "server_Municion.h"
#include <array>

class Armamento {
public:
    Armamento(int tipo);
    Armamento(const Armamento& orig);
    Municion* dispararA (std::array<double,2> posicion, Objeto& objetivo);
    virtual ~Armamento();
private:
    int tipo; //Representa el tipo de municion
    Municion getMunicion(int tipo);
};

#endif /* ARMAMENTO_H */

