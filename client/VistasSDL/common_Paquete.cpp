#include "common_Paquete.h"
using std::string;
using std::stoi;

Paquete::Paquete(std::string mensaje) {
    id = stoi(mensaje.substr(0,3));
    comando = stoi(mensaje.substr(3,1));
    if (comando == matar){
        return ;
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


