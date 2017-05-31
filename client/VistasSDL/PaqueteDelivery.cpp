#include "Header Files/PaqueteDelivery.h"
PaqueteDelivery::PaqueteDelivery(const Socket &socket, ColaPaquetes &cola)
    : socket(socket), cola(cola), salir(false) {}

//void PaqueteDelivery::run() {
//    while (!salir){
//
//    }
//
//}
