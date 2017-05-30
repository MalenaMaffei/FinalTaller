/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Municion.h
 * Author: usuario
 *
 * Created on 27 de mayo de 2017, 17:24
 */

#ifndef MUNICION_H
#define MUNICION_H


#include "server_Objeto.h"
#include "server_Movible.h"

class Unidad;
class Bloque;

class Municion : public Movible {
    public:
        Municion(int vida, double ancho, double alto, int tipo, int danio);
        Municion(const Municion& orig);
        Municion &operator=(Municion &orig);
        Municion(Municion &&orig);
        Municion &operator=(Municion &&orig);
        void setObjetivo (Objeto& objetivo);
        int getTipo();
        int getDanio();
        void colisionar(Municion& municion) override;
        void colisionar(Unidad& personaje) override;
        void colisionar(Bloque& bloque) override;
        void colisionar(Objeto& objeto) override;
        virtual ~Municion();
    private:
        Objeto* objetivo; //No se puede guardar un Objeto porque es abstracto, 
                            //si se puede un puntero a Objeto.
        int tipo;
        int danio;
};

#endif /* MUNICION_H */

