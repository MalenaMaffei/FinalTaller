#include <stdexcept>
#include "Header Files/PaqueteAccion.h"
#include "Header Files/CodigosPaquete.h"
#include "Header Files/constantes.h"
#include <string>
#include <cmath>
#define ESCALA 100
using std::string;
using std::to_string;

string PaqueteAccion::crearCampo(int campo, int contenido) {
    string contenidoStr = to_string(contenido);
    return crearCampo(campo, contenidoStr);
}

string PaqueteAccion::crearCampo(int campo, std::string contenidoStr) {
    int filler = campo - contenidoStr.size();
    if (filler < 0){
        throw std::invalid_argument("Creando PaqueteAccion: El contenido: "+
            contenidoStr+" fue mayor al largo del campo "+to_string(campo));
    } else if (filler > 0){
        for (int i = 0; i < filler; ++i) {
            contenidoStr.insert(0,  "0");
        }
    }
    return contenidoStr;
}

void PaqueteAccion::atacar(string idAgresor, string idAgredido) {
    string agresor = crearCampo(codigos.id, idAgresor);
    string agredido = crearCampo(codigos.id, idAgredido);
    string comando = crearCampo(codigos.comando, codigos.disparar);
    mensaje = comando + agresor + agredido;
}

void PaqueteAccion::crear(string id, int tipo) {
    string creadorStr = crearCampo(codigos.id, id);
    string tipoStr = crearCampo(codigos.tipo, tipo);
    string comando = crearCampo(codigos.comando, codigos.crear);

    mensaje = comando + creadorStr + tipoStr;
}

void PaqueteAccion::pedirInfo(string id) {
    string idStr = crearCampo(codigos.id, id);
    string comando = crearCampo(codigos.comando, codigos.infoUnidad);
    mensaje = comando + idStr;
}

int PaqueteAccion::coordToClient(double coord) {
    return static_cast<int>(std::round((coord/double(ESCALA))*TILE_WIDTH));
}

int PaqueteAccion::coordToServer(double coord) {
    return static_cast<int>(std::round((coord/double(TILE_WIDTH))*ESCALA));
}

void PaqueteAccion::mover(string id, int x, int y) {
    string idStr = crearCampo(codigos.id, id);

    x = coordToServer(x);
    y = coordToServer(y);

    string xStr = crearCampo(codigos.x, x);
    string yStr = crearCampo(codigos.y, y);

    string comando = crearCampo(codigos.comando, codigos.mover);
    mensaje = comando + idStr + xStr + yStr;
}

string PaqueteAccion::getId() const {
    return mensaje.substr(codigos.posId,codigos.id);
}

int PaqueteAccion::getX() {
    if (getComando() == codigos.matar){
        throw std::invalid_argument("PaqueteAccion matar no tiene campo X.");
    }
    int xServer = toInt(mensaje.substr(codigos.posX,codigos.x));
    int xClient = coordToClient(xServer);
    return xClient;
}

int PaqueteAccion::getY() {
    if (getComando() == codigos.matar){
        throw std::invalid_argument("PaqueteAccion matar no tiene campo Y.");
    }
    int yServer = toInt(mensaje.substr(codigos.posY,codigos.y));
    int yClient = coordToClient(yServer);
    return yClient;
}

int PaqueteAccion::getTipo() const {
    if (getComando() != codigos.crear){
        throw std::invalid_argument("PaqueteAccion "+to_string(getComando())+
            " no tiene campo Tipo.");
    }
    return toInt(mensaje.substr(codigos.posTipo,codigos.tipo));
}

int PaqueteAccion::getColor() const {
    if (getComando() != codigos.crear){
        throw std::invalid_argument("PaqueteAccion "+to_string(getComando())+
            " no tiene campo Color.");
    }
    return toInt(mensaje.substr(codigos.posColor,codigos.color));
}

PaqueteAccion::PaqueteAccion(Paquete paquete) {
    setMensaje(paquete.getMensaje());
}

PaqueteAccion::PaqueteAccion() {}


