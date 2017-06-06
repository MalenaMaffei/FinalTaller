#include "Header Files/common_PaqueteEntrada.h"
#include <string>
using std::string;
using std::stoi;
using std::map;

PaqueteEntrada::PaqueteEntrada(std::string mensaje) {
    id = stoi(mensaje.substr(0,3));
    comando = stoi(mensaje.substr(3,1));
    if (comando == matar){
        return;
    }

    x = stoi(mensaje.substr(4,4));
    y = stoi(mensaje.substr(8,4));
    if (comando == crear){
        esMio = stoi(mensaje.substr(12,1));
        tipo = stoi(mensaje.substr(13,1));
        if (mensaje.size() == 15){
            color = stoi(mensaje.substr(14,1));
        }
    }
}

int PaqueteEntrada::getId() const {
    return id;
}
int PaqueteEntrada::getComando() const {
    return comando;
}
int PaqueteEntrada::getX() const {
    return x;
}
int PaqueteEntrada::getY() const {
    return y;
}
int PaqueteEntrada::getTipo() const {
    return tipo;
}
bool PaqueteEntrada::isEsMio() const {
    return esMio;
}
int PaqueteEntrada::getColor() const {
    return color;
}



