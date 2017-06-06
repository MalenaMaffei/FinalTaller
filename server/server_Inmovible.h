/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inmovible.h
 * Author: usuario
 *
 * Created on 30 de mayo de 2017, 14:28
 */

#ifndef INMOVIBLE_H
#define INMOVIBLE_H

#include "server_Objeto.h"

class Inmovible : public Objeto{
    public:
        Inmovible(int vida, double ancho, double alto, int tipo);
        Inmovible(const Inmovible& orig);
        Inmovible& operator=(const Inmovible& orig);
        
        // Las colisiones se resuelven en los hijos
        virtual void colisionar(Objeto& objeto) = 0;
        virtual void colisionar(Municion& municion) = 0;
        virtual void colisionar(Unidad& personaje) = 0;
        virtual void colisionar(Bloque& bloque) = 0;        
        
        virtual ~Inmovible();
    private:

};

#endif /* INMOVIBLE_H */

