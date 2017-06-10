#include <stdexcept>
#include "Header Files/Paquete.h"
#include "Header Files/common_CodigosPaquete.h"
#include <string>
using std::string;
using std::to_string;

string Paquete::crearCampo(int campo, int contenido) {
    string contenidoStr = to_string(contenido);
    return crearCampo(campo, contenidoStr);
}

string Paquete::crearCampo(int campo, std::string contenidoStr) {
    int filler = campo - contenidoStr.size();
    if (filler < 0){
        throw std::invalid_argument("Creando Paquete: El contenido: "+
            contenidoStr+" fue mayor al largo del campo "+to_string(campo));
    } else if (filler > 0){
        for (int i = 0; i < filler; ++i) {
            contenidoStr.insert(0,  "0");
        }
    }
    return contenidoStr;
}


void Paquete::atacar(string idAgresor, string idAgredido) {
    string agresor = crearCampo(codigos.id, idAgresor);
    string agredido = crearCampo(codigos.id, idAgredido);
    string comando = crearCampo(codigos.comando, codigos.disparar);
    mensaje = comando + agresor + agredido;
}

void Paquete::crear(string id, int x, int y, int tipo) {
    string creadorStr = crearCampo(codigos.id, id);
    string xStr = crearCampo(codigos.x, x);
    string yStr = crearCampo(codigos.y, y);
    string tipoStr = crearCampo(codigos.tipo, tipo);
    string comando = crearCampo(codigos.comando, codigos.crear);

    mensaje = comando + creadorStr + xStr + yStr + tipoStr;
}

void Paquete::pedirInfo(string id) {
    string idStr = crearCampo(codigos.id, id);
    string comando = crearCampo(codigos.comando, codigos.info);
    mensaje = comando + idStr;
}

void Paquete::mover(string id, int x, int y) {
    string idStr = crearCampo(codigos.id, id);
    string xStr = crearCampo(codigos.x, x);
    string yStr = crearCampo(codigos.y, y);
    string comando = crearCampo(codigos.comando, codigos.mover);
    mensaje = comando + idStr + xStr + yStr;
}

string & Paquete::getMensaje()  {
    return mensaje;
}

void Paquete::setMensaje(const string &mensaje) {
    Paquete::mensaje = mensaje;

}

string Paquete::getId() const {
    return mensaje.substr(1,codigos.id);
}

int Paquete::getComando() const {
    return stoi(mensaje.substr(0,codigos.comando));
}

int Paquete::getX() const {
    if (getComando() == codigos.matar){
        throw std::invalid_argument("Paquete matar no tiene campo X.");
    }
    return stoi(mensaje.substr(4,codigos.x));
}

int Paquete::getY() const {
    if (getComando() == codigos.matar){
        throw std::invalid_argument("Paquete matar no tiene campo Y.");
    }
    return stoi(mensaje.substr(8,codigos.y));
}

int Paquete::getTipo() const {
    if (getComando() != codigos.crear){
        throw std::invalid_argument("Paquete "+to_string(getComando())+" no "
            "tiene campo Tipo.");
    }
    return stoi(mensaje.substr(12,codigos.tipo));
}

int Paquete::getColor() const {
    if (getComando() != codigos.crear){
        throw std::invalid_argument("Paquete "+to_string(getComando())+" no "
            "tiene campo Color.");
    }
    return stoi(mensaje.substr(14,codigos.color));
}



