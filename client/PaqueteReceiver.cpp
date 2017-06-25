#include "Header Files/PaqueteReceiver.h"
#include "Header Files/common_SocketException.h"
#include <string>
#include <chrono>
PaqueteReceiver::PaqueteReceiver(Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {
    while (!salir){
        string mensaje;
        try {
            mensaje = socket.ReceiveStrWLen();
//            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        } catch(SocketException& e ){
            displayError(e);
            shutdown();
            continue;
        }

        Paquete paquete;
        paquete.setMensaje(mensaje);
        if (paquete.getComando() != 5){
            printf("paquete recibido: %s\n", mensaje.c_str());
        }
        cola.encolar(paquete);

    }
}
