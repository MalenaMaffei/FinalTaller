
#include <iostream>
#include "ColaMensajes.h"


void ColaMensajes::encolar(Mensaje paquete){
    std::unique_lock<std::mutex> mlock(m);
    paquetes.push(paquete);
}

Mensaje ColaMensajes::desencolar() {
    std::unique_lock<std::mutex> mlock(m);
    Mensaje paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}

int ColaMensajes::size() {
	return paquetes.size();
}

bool ColaMensajes::isEmpty() {
    return paquetes.empty();
}
