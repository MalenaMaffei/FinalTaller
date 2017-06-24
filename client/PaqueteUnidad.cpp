#include "PaqueteUnidad.h"

PaqueteUnidad::PaqueteUnidad(const std::string &mensaje) : mensaje(mensaje) {}

int PaqueteUnidad::getTipo() {
    return std::stoi(mensaje.substr(4,codigos.tipo));
}

float PaqueteUnidad::getVida() {
    float vida  = std::stoi(mensaje.substr(6,3));
    float cienporciento = 100;
    return vida/cienporciento;
}
