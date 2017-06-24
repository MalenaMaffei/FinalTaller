#include "PaqueteUnidad.h"

PaqueteUnidad::PaqueteUnidad(const std::string &mensaje) : mensaje(mensaje) {}

int PaqueteUnidad::getTipo() {
    return std::stoi(mensaje.substr(4,codigos.tipo));
}
int PaqueteUnidad::getVida() {
    return std::stoi(mensaje.substr(6,3));
}
