#include <iostream>
#include "Header Files/PaqueteDelivery.h"
PaqueteDelivery::PaqueteDelivery(const Socket &socket, ColaPaquetes &cola)
    : socket(socket), cola(cola), salir(false) {}

void PaqueteDelivery::shutdown() {
    salir = true;
    cola.cerrar();
}

void PaqueteDelivery::displayError(SocketException &e) {
    std::cerr << e.what() << std::endl;
}

