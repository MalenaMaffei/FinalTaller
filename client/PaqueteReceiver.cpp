#include "Header Files/PaqueteReceiver.h"
#include "Header Files/common_SocketException.h"
#include <string>
#include <chrono>
PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {
    while (!salir){
        string mensaje;
        try {
//            Se va a quedar bloqueado acá hasta que llegue un paquete
            mensaje = socket.ReceiveStrWLen();
        } catch(SocketException& e ){
            logger->logACerr(e.what());
            shutdown();
            continue;
        }

        Paquete paquete;
        paquete.setMensaje(mensaje);
        cola.encolar(paquete);
    }
}
