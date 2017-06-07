/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: usuario
 *
 * Created on 29 de mayo de 2017, 10:00
 */

#ifndef JUEGO_H
#define JUEGO_H

#include "server_Mapa.h"
#include "server_Movible.h"
#include "server_Inmovible.h"
#include <vector>
#include <map>
#include "common_Socket.h"
#include "common_Thread.h"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <pthread.h>

class Juego : public Thread {
public:
    Juego(std::queue<std::string>* colaDeRecibidos, std::mutex* m, 
            std::condition_variable* cond, Socket* socket);
    void moverUnidades();
    bool hayGanador();
    void chequearColisiones();
    void eliminarMuertos();
    void actualizarDisparos();
    void actualizarEdificios();
    void actualizarRecibidos();
    void enviarMensajesEncolados();
    void run() override;
    virtual ~Juego();
private:
    
    void recibirMover(std::string mensaje);
    void recibirDisparar(std::string mensaje);
    void recibirObtenerInfo(std::string mensaje);
    
    void enviarInfo(std::string id);
    void enviarCrear(Objeto* objeto);
    
    Mapa mapa;
    
    std::queue<std::string>* colaDeRecibidos;
    std::mutex* m;
    std::condition_variable* cond;

    std::queue<std::string> colaDeEnviados;

    Socket* socket;
    
    //No puedo instanciar Movible porque es abstracto
    std::array<int,4> banderasPorEquipo;
    std::map<std::string,Movible*> movibles; //Robots, vehiculos, balas
    std::map<std::string,Inmovible*> inmovibles; //Bloques, puentes, banderas
    std::map<std::string,Edificio*> edificios; //Edificio
    int proximoIDMovible;

    
};

#endif /* JUEGO_H */

