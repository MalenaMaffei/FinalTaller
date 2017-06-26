#include <iostream>
#include "Header Files/ColaPaquetesVieja.h"

ColaPaquetesVieja::ColaPaquetesVieja() : salir(false){}

void ColaPaquetesVieja::encolar(Paquete paquete){
    std::unique_lock<std::mutex> mlock(m);
    paquetes.push(paquete);
}

Paquete ColaPaquetesVieja::desencolar() {
    std::unique_lock<std::mutex> mlock(m);
    Paquete paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}

bool ColaPaquetesVieja::isEmpty() {
    return paquetes.empty();
}

void ColaPaquetesVieja::cerrar() {
    salir = true;
}

bool ColaPaquetesVieja::estaCerrada() {
    return salir;
}

