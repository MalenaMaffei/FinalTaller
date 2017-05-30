/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Robot.h
 * Author: usuario
 *
 * Created on 27 de mayo de 2017, 16:45
 */

#ifndef UNIDAD_H
#define UNIDAD_H

#include "server_Objeto.h"
#include "server_Movible.h"
#include "server_Municion.h"
#include "server_Armamento.h"
#include "server_Bloque.h"

class Unidad : public Movible {
    public:
        Unidad(int vida, double ancho, double alto, int frecuenciaDisparo,
                    int alcance, int tipoArmamento);
        Municion* dispararA(Objeto& objetivo);
        void colisionar(Municion& municion) override;
        void colisionar(Objeto& objeto) override;
        void colisionar (Unidad& personaje) override;
        void colisionar(Bloque& bloque) override;
        virtual ~Unidad();
    private:
        Armamento armamento;
        int frecuenciaDisparo;
        int alcance;
};

#endif /* UNIDAD_H */

