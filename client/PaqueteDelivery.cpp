#include <iostream>
#include "Header Files/PaqueteDelivery.h"
PaqueteDelivery::PaqueteDelivery(const Socket &socket, ColaPaquetes &cola)
    : socket(socket), cola(cola), salir(false) {}

void PaqueteDelivery::shutdown() {
    printf("entro en shutdown\n");
    salir = true;
    cola.cerrar();
    printf("cerro la cola\n");
}

void PaqueteDelivery::displayError(SocketException &e) {
    std::cerr << e.what() << std::endl;
}

