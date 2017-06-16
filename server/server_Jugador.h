/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReceptorCliente.h
 * Author: usuario
 *
 * Created on 13 de junio de 2017, 19:45
 */

#ifndef RECEPTORCLIENTE_H
#define RECEPTORCLIENTE_H

#include "common_Thread.h"
#include "common_Socket.h"
#include "ColaMensajes.h"

class Jugador : public Thread {
public:
    Jugador(Socket &socket, ColaMensajes &colaDeRecibidos);
    void enviarMensaje(std::string& mensaje);
    void run();
    virtual ~Jugador();
private:
    Socket socket;
    int id;
    int equipo;
    ColaMensajes& colaDeRecibidos;
};

#endif /* RECEPTORCLIENTE_H */

