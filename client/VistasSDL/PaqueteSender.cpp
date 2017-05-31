#include "Header Files/PaqueteSender.h"
PaqueteSender::PaqueteSender(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteSender::run() {
//TODO ojo aca se fija todo el tiempo si hay algo que mandar, para esto era
// qe hay que ver si usar priority queue

    while (! salir){
        if(!cola.isEmpty()){
            Paquete paquete = cola.desencolar();
//            socket.SendStrWLen(paquete.getString());
        }
    }

}

