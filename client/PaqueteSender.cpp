#include <iostream>
#include <condition_variable>
#include "Header Files/PaqueteSender.h"
#include "Header Files/common_SocketException.h"
#include <chrono>
PaqueteSender::PaqueteSender(const Socket &socket,
                             ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteSender::run() {
    while (! salir){
        Paquete paquete;
        try {
//        Se va a quedar bloqueado aca hasta que haya algo para
// desencolar.
            paquete = cola.desencolarBloqueante();
        } catch(std::runtime_error& e) {
            continue;
        }

        try {
            socket.SendStrWLen(paquete.getMensaje());
        } catch(SocketException& e){
//            displayError(e);
            shutdown();
            continue;
        }
    }
}

