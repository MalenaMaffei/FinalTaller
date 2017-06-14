#include <iostream>
#include "Header Files/ColaPaquetes.h"

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
