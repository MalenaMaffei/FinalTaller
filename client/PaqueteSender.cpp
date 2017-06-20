#include <iostream>
#include <condition_variable>
#include "Header Files/PaqueteSender.h"
#include "Header Files/common_SocketException.h"
#include <chrono>
PaqueteSender::PaqueteSender(const Socket &socket,
                             ColaSalida &cola,
                             std::mutex *m,
                             std::condition_variable *cond)
    : PaqueteDelivery(socket, cola), m(m), cond_v(cond) {}

void PaqueteSender::run() {
//    std::chrono::duration<int> dosMinutos(120);
    while (! salir){
//        std::unique_lock<std::mutex> lk(*m);
//        if (cola.isEmpty()) {
//            cond_v->wait_for(lk, dosMinutos);
//        }

//        if (!cola.isEmpty()){

//        Se va a quedar bloqueado aca hasta que haya algo para desencolar.
        Paquete paquete;
        try {
            paquete = cola.desencolar();
        } catch(std::runtime_error& e) {
            shutdown();
            continue;
        }


        try {
            socket.SendStrWLen(paquete.getMensaje());
            printf("el paquete mandado dice %s\n",
                   paquete.getMensaje().c_str());
        } catch(SocketException& e){
            displayError(e);
            shutdown();
            continue;
        }
//        }
    }
}

