#include "Header Files/PaqueteReceiver.h"
PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {
    while (!salir){
        string mensaje;
        mensaje = socket.ReceiveStrWLen();
        Paquete paquete(mensaje);
        cola.encolar(paquete);
    }
}
