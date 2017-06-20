#include <iostream>
#include "Header Files/ColaPaquetes.h"

ColaPaquetes::ColaPaquetes() : salir(false){}

void ColaPaquetes::encolar(Paquete paquete){
    std::unique_lock<std::mutex> mlock(m);
    paquetes.push(paquete);
}

Paquete ColaPaquetes::desencolar() {
    std::unique_lock<std::mutex> mlock(m);
    Paquete paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}

bool ColaPaquetes::isEmpty() {
    return paquetes.empty();
}

void ColaPaquetes::cerrar() {
    salir = true;
}

bool ColaPaquetes::estaCerrada() {
    return salir;
}

