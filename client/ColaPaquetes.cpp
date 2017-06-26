#include "Header Files/ColaPaquetes.h"
//TODO refactorizar para que pueda usar mutex madre
ColaPaquetes::ColaPaquetes() : salir(false) {}

void ColaPaquetes::encolar(Paquete paquete) {
    bool estabaVAcia = paquetes.empty();
    std::unique_lock<std::mutex> mlock(m);
    paquetes.push(paquete);
    if (estabaVAcia){
        cond_v.notify_one();
    }
}

Paquete ColaPaquetes::desencolarBloqueante() {
    std::unique_lock<std::mutex> lk(m);
    if (isEmpty()) {
        printf("esperando que haya para desencolar\n");
        cond_v.wait(lk);
    }
// Porque la cond_v pudo haber sido despertada por cerrar.
    if (!isEmpty()){
        printf("desencolo uno\n");
        Paquete paquete = paquetes.front();
        paquetes.pop();
        return paquete;
    } else {
        throw std::runtime_error("Cola cerrada");
    }
}

Paquete ColaPaquetes::desencolar() {
    std::unique_lock<std::mutex> mlock(m);
    Paquete paquete = paquetes.front();
    paquetes.pop();
    return paquete;
}

void ColaPaquetes::cerrar() {
    salir = true;
    cond_v.notify_one();
}

bool ColaPaquetes::isEmpty() {
    return paquetes.empty();
}

bool ColaPaquetes::estaCerrada() {
    return salir;
}