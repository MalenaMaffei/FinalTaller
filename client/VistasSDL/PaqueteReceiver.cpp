#include "Header Files/PaqueteReceiver.h"
#include <string>

PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {
//    while (!salir){
//        string mensaje;
//        mensaje = socket.ReceiveStrWLen();
//        Paquete paquete;
//        paquete.setMensaje(mensaje);
//        cola.encolar(paquete);
//    }
}
