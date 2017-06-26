#include "Header Files/PaqueteUnidad.h"
#include <string>
PaqueteUnidad::PaqueteUnidad(const std::string &mensaje) : mensaje(mensaje) {}
//TODO poner los enums correspondientes
int PaqueteUnidad::getTipo() {
    return std::stoi(mensaje.substr(4,codigos.tipo));
}

float PaqueteUnidad::getVida() {
    float vida  = std::stoi(mensaje.substr(6,3));
    float cienporciento = 100;
    return vida/cienporciento;
}

int PaqueteUnidad::getColor() {
    return std::stoi(mensaje.substr(9,1));
}
