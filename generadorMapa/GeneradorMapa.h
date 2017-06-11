/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeneradorMapa.h
 * Author: usuario
 *
 * Created on 21 de mayo de 2017, 12:47
 */

#ifndef GENERADORMAPA_H
#define GENERADORMAPA_H

#include <array>

class GeneradorMapa {
public:
    GeneradorMapa();
    void generarMapa();
    void generarMapa(const std::string& nombre);
    virtual ~GeneradorMapa();
private:

};

#endif /* GENERADORMAPA_H */

