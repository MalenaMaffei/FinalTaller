/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bloque.h
 * Author: usuario
 *
 * Created on 30 de mayo de 2017, 14:55
 */

#ifndef BLOQUE_H
#define BLOQUE_H

#include "server_Inmovible.h"
#include "server_Unidad.h"
#include "server_Municion.h"

class Bloque : public Inmovible {
public:
    Bloque(int vida, double ancho, double alto);
    void colisionar(Municion& municion) override;
    void colisionar(Objeto& objeto) override;
    void colisionar (Unidad& personaje) override;
    void colisionar(Bloque& bloque) override; 
    
    virtual ~Bloque();
private:
    
    

};

#endif /* BLOQUE_H */

