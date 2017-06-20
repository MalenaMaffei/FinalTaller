#include <iostream>
#include <condition_variable>
#include "Header Files/PaqueteSender.h"
#include "Header Files/common_SocketException.h"
#include <chrono>
PaqueteSender::PaqueteSender(const Socket &socket,
                             ColaSalida &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteSender::run() {
    while (! salir){
        Paquete paquete;
        try {
//        Se va a quedar bloqueado aca hasta que haya algo para desencolar.
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
    }
}

