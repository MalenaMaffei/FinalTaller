#include "Header Files/PaqueteReceiver.h"
#include <string>
#include <chrono>
PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {
    while (!salir){
        string mensaje;
		printf("recibir\n");
        mensaje = socket.ReceiveStrWLen();
		printf("paquete %s\n", mensaje.c_str());
        Paquete paquete;
        paquete.setMensaje(mensaje);
        cola.encolar(paquete);
    }
}
