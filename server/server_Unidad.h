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

#include "server_Bloque.h"

enum estado {
    DISPARAR,
    REPOSO
};

class Unidad : public Movible {
    public:
        Unidad(int vida, double ancho, double alto, int frecuenciaDisparo,
                    int alcance, int velocidad, int tipo, int armamento);
        void dispararA(std::string objetivo);
        int getArmamento();
        std::string getBandera();
        std::string puedeDisparar() override;
        bool obtuvoBandera() override;
        void colisionar(Municion& municion) override;
        void colisionar(Objeto& objeto) override;
        void colisionar (Unidad& personaje) override;
        void colisionar(Bloque& bloque) override;
        void colisionar(Edificio& edificio) override;
        void colisionar (Bandera& bandera) override;
        virtual ~Unidad();
    private:
        std::string bandera;
        int frecuenciaDisparo;
        int tiempoADisparo;
        int alcance;
        int estado;
        int armamento;
};

#endif /* UNIDAD_H */

