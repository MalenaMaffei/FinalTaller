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
            mensaje = socket.ReceiveStrWLen();
        } catch(SocketException& e ){
//            TODO se podria decir, si ya estaba salir==true, es que cerre yo
// al socket entonces no muestro nada. si salir==false, se cerro desde el server
            displayError(e);
            shutdown();
            continue;
        }

        Paquete paquete;
        paquete.setMensaje(mensaje);
//        if (paquete.getComando() != 5){
//            printf("paquete recibido: %s\n", mensaje.c_str());
//        }
        cola.encolar(paquete);

    }
}
