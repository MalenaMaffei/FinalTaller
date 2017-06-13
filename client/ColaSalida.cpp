#include "Header Files/ColaSalida.h"

ColaSalida::ColaSalida(std::mutex *m, std::condition_variable *cond_v)
    : m(m), cond_v(cond_v) {}

void ColaSalida::encolar(Paquete paquete) {
    bool estabaVAcia = paquetes.empty();
    std::unique_lock<std::mutex> mlock(*m);
    paquetes.push(paquete);
    if (estabaVAcia){
        cond_v->notify_one();
    }
}

Paquete ColaSalida::desencolar() {
    Paquete paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}
