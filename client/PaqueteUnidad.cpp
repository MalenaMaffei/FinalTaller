#include "Header Files/PaqueteUnidad.h"
#include <string>
PaqueteUnidad::PaqueteUnidad(const std::string &mensaje)  {
    setMensaje(mensaje);
}

int PaqueteUnidad::getTipo() {
    return toInt(mensaje.substr(posTipo,codigos.tipo));
}

float PaqueteUnidad::getVida() {
    float vida  = toInt(mensaje.substr(posVida,largoVida));
    float cienporciento = 100;
    return vida/cienporciento;
}

int PaqueteUnidad::getColor() {
    return toInt(mensaje.substr(posColor,codigos.color));
}
