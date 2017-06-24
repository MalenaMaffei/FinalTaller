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
            printf("error en la cola: %s\n", e.what());
            shutdown();
            continue;
        }

        try {
            printf("el paquete a mandadar dice %s.",
                   paquete.getMensaje().c_str());
            socket.SendStrWLen(paquete.getMensaje());
            printf(" y ya se mando\n");
        } catch(SocketException& e){
            displayError(e);
            shutdown();
            continue;
        }
    }
}

