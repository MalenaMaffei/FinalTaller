#include <stdexcept>
#include "Paquete.h"
#include "Header Files/common_CodigosPaquete.h"
using std::string;
using std::to_string;

std::string Paquete::crearCampo(int campo, int contenido) {
    string contenidoStr = to_string(contenido);
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

void Paquete::atacar(int idAgresor, int idAgredido) {
    CodigosPaquete codigos;
    string agresor = crearCampo(codigos.id, idAgresor);
    string agredido = crearCampo(codigos.id, idAgredido);
    string comando = crearCampo(codigos.comando, codigos.disparar);
    mensaje = comando + agresor + agredido;
}

void Paquete::crear(int id, int x, int y, int tipo) {
    CodigosPaquete codigos;
    string creadorStr = crearCampo(codigos.id, id);
    string xStr = crearCampo(codigos.x, x);
    string yStr = crearCampo(codigos.y, y);
    string tipoStr = crearCampo(codigos.tipo, tipo);
    string comando = crearCampo(codigos.comando, codigos.crear);

    mensaje = comando + creadorStr + xStr + yStr + tipoStr;
}

void Paquete::pedirInfo(int id) {
    CodigosPaquete codigos;
    string idStr = crearCampo(codigos.id, id);
    string comando = crearCampo(codigos.comando, codigos.info);
    mensaje = comando + idStr;
}

void Paquete::mover(int id, int x, int y) {
    CodigosPaquete codigos;
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



