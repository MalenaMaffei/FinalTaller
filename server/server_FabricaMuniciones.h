/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaMuniciones.h
 * Author: usuario
 *
 * Created on 27 de mayo de 2017, 17:30
 */

#ifndef FABRICAMUNICIONES_H
#define FABRICAMUNICIONES_H

#include <stddef.h>
#include <map>
#include "server_Municion.h"

class FabricaMuniciones {
public:
    FabricaMuniciones(); 
    Municion* getMunicion(int tipo);
private:
    //Clave: tipo de municion
    //Valor: daño
    std::map<int,int> municiones;

};

#endif /* FABRICAMUNICIONES_H */

