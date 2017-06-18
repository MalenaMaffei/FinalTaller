/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mensaje.h
 * Author: usuario
 *
 * Created on 18 de junio de 2017, 14:53
 */

#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>

class Mensaje {
public:
    Mensaje(std::string mensaje, int id);
    std::string getMensaje();
    int getId();
    virtual ~Mensaje();
private:
    std::string mensaje;
    int id;
};

#endif /* MENSAJE_H */

