#include <iostream>
#include "Header Files/ColaPaquetes.h"
#include "Header Files/common_PaqueteEntrada.h"

void ColaPaquetes::encolar(Paquete paquete){
    paquetes.push(paquete);
}

Paquete ColaPaquetes::desencolar() {
    Paquete paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}

bool ColaPaquetes::isEmpty() {
    return paquetes.empty();
}