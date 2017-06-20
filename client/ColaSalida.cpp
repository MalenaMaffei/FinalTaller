#include "Header Files/ColaSalida.h"
//TODO refactorizar para que pueda usar mutex madre
ColaSalida::ColaSalida(std::mutex &m, std::condition_variable &cond_v)
    : m(m), cond_v(cond_v) {}

void ColaSalida::encolar(Paquete paquete) {
    bool estabaVAcia = paquetes.empty();
    std::unique_lock<std::mutex> mlock(m);
    paquetes.push(paquete);
    if (estabaVAcia){
        cond_v.notify_one();
    }
}

Paquete ColaSalida::desencolar() {
    std::unique_lock<std::mutex> lk(m);
//    std::chrono::duration<int> dosMinutos(120);
    if (isEmpty()) {
        cond_v.wait(lk);
    }
// Porque la cond_v pudo haber sido despertada por cerrar.
    if (!isEmpty()){
        Paquete paquete = paquetes.front();
        paquetes.pop();
        return paquete;
    } else {
        throw std::runtime_error("Cola cerrada");
    }
}

void ColaSalida::cerrar() {
    ColaPaquetes::cerrar();
    cond_v.notify_one();
}
