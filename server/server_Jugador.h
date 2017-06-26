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
#include "server_BoolProtected.h"

class Jugador : public Thread {
public:
    Jugador(Socket &socket, ColaMensajes &colaDeRecibidos, int id);
    void enviarMensaje(std::string& mensaje, int id);
    void finalizar();
    void setEquipo(int equipo);
    int getEquipo();
    int getId();
    void run();
    virtual ~Jugador();
private:
    BoolProtected perdio;
    BoolProtected salir;
    Socket socket;
    int equipo;
    ColaMensajes& colaDeRecibidos;
    int id;
};

#endif /* RECEPTORCLIENTE_H */

