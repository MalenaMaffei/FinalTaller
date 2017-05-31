#include "Header Files/ColaPaquetes.h"

void ColaPaquetes::encolar(Paquete& paquete){
    paquetes.push(paquete);
}

Paquete ColaPaquetes::desencolar() {
    Paquete paquete = paquetes.front();
    paquetes.pop();
}
bool ColaPaquetes::isEmpty() {
    return paquetes.empty();
}
