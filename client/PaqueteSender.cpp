#include <iostream>
#include <condition_variable>
#include "Header Files/PaqueteSender.h"
#include <chrono>
PaqueteSender::PaqueteSender(const Socket &socket,
                             ColaSalida &cola,
                             std::mutex *m,
                             std::condition_variable *cond)
    : PaqueteDelivery(socket, cola), m(m), cond_v(cond) {}

void PaqueteSender::run() {

    std::chrono::duration<int> dosMinutos(120);
    while (! salir){
        std::unique_lock<std::mutex> lk(*m);
        while (cola.isEmpty()) {
            cond_v->wait_for(lk, dosMinutos);
        }

        if (!cola.isEmpty()){
            Paquete paquete = cola.desencolar();
            socket.SendStrWLen(paquete.getMensaje());
            printf("el paquete mandado dice %s\n", paquete.getMensaje().c_str
                ());
        }
    }
}

