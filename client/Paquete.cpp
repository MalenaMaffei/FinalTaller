#include "Header Files/Paquete.h"
#include <stdexcept>
int Paquete::toInt(std::string str) const{
    try {
        return stoi(str);
    } catch(std::invalid_argument& e){
        throw std::invalid_argument("se intento transformar: "+str+" a int en"
            " un PaqueteAccion con mensaje: "+ mensaje);
    }
}

int Paquete::getComando() const {
    return toInt(mensaje.substr(codigos.posComando,codigos.comando));
}

std::string &Paquete::getMensaje() {
    return mensaje;
}

void Paquete::setMensaje(const std::string &mensaje) {
    Paquete::mensaje = mensaje;
}
Paquete::Paquete() {}
