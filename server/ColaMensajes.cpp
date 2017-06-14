
#include <iostream>
#include "ColaMensajes.h"


void ColaMensajes::encolar(const std::string& paquete){
    std::unique_lock<std::mutex> mlock(m);
    paquetes.push(paquete);
}

std::string ColaMensajes::desencolar() {
    std::unique_lock<std::mutex> mlock(m);
    std::string paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}

bool ColaMensajes::isEmpty() {
    return paquetes.empty();
}
