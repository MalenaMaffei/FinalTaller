#include <iostream>
#include "Header Files/PaqueteTransporte.h"
#include "Header Files/ColaPaquetes.h"
PaqueteTransporte::PaqueteTransporte(const Socket &socket, ColaPaquetes &cola)
    : socket(socket), cola(cola), salir(false) {}

void PaqueteTransporte::shutdown() {
    salir = true;
    cola.cerrar();
}
