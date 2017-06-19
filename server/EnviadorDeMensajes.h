/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnviadorDeMensajes.h
 * Author: usuario
 *
 * Created on 19 de junio de 2017, 01:17
 */

#ifndef ENVIADORDEMENSAJES_H
#define ENVIADORDEMENSAJES_H

#include "common_Thread.h"
#include "ColaMensajes.h"
#include "server_Jugador.h"
#include <vector>

class EnviadorDeMensajes : public Thread {
public:
    EnviadorDeMensajes(ColaMensajes& colaDeEnviados, 
                        std::vector<Jugador*> jugadores);
    void run();
    virtual ~EnviadorDeMensajes();
private:
    ColaMensajes& colaDeEnviados;
    std::vector<Jugador*> jugadores;
};

#endif /* ENVIADORDEMENSAJES_H */

