/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bandera.h
 * Author: usuario
 *
 * Created on 4 de junio de 2017, 17:23
 */

#ifndef BANDERA_H
#define BANDERA_H

#include "server_Inmovible.h"

class Bandera : public Inmovible {
public:
    Bandera(double ancho, double alto, int tipo);
    bool estaVivo() override;
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar(Unidad& personaje) override;
    void colisionar(Bloque& bloque) override; 
    void colisionar(Bandera& bandera) override; 
    void colisionar(Edificio& edificio) override; 
    int getEquipo();
    virtual ~Bandera();
private:
    int idEquipo;
};

#endif /* BANDERA_H */

