/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Terreno.h
 * Author: usuario
 *
 * Created on 23 de mayo de 2017, 16:17
 */

#ifndef TERRENO_H
#define TERRENO_H

class Terreno {
public:
    Terreno(int factor, int id);
    virtual ~Terreno();
private:
    int factor;
    int tipo;
};

#endif /* TERRENO_H */

