#include "Header Files/PaqueteFabrica.h"
#include <map>
using std::string;
PaqueteFabrica::PaqueteFabrica(const std::string &mensaje) : mensaje(mensaje) {}



string PaqueteFabrica::getId() {
    return mensaje.substr(posId, id);
}

int PaqueteFabrica::getTipoFabrica() {
    return std::stoi(mensaje.substr(posTipoFabrica, tipo));
}

int PaqueteFabrica::getVidaFabrica() {
    return std::stoi(mensaje.substr(posVida, vida));
}

std::map<int,std::string> PaqueteFabrica::getConstruibles() {
    std::map<int,std::string> construibles;
    int cant = getCantConstuibles();
    int currTipo;
    string currTiempo;
    int pos = posCant+cant;
    int offset;
    for (int i = 0; i < cant; ++i) {
        offset = (tiempo + tipo)*i;
        currTipo = std::stoi(mensaje.substr(pos + offset, tipo));
        currTiempo = mensaje.substr(pos + offset + tipo, tiempo);
        construibles[currTipo] = currTiempo;
    }
    return construibles;
}

bool PaqueteFabrica::estaConstruyendo() {
    int pos = getOffsetConstruibles();
    return std::stoi(mensaje.substr(pos, isConstruyendo));
}

int PaqueteFabrica::tipoEnConstruccion() {
//    if (!estaConstruyendo()){
////        TODO lanzar excepcion aca
//    }
    int pos = getOffsetConstruibles() + isConstruyendo;
    return std::stoi(mensaje.substr(pos, tipo));
}

int PaqueteFabrica::porcentajeConstruido() {
    //    if (!estaConstruyendo()){
////        TODO lanzar excepcion aca
//    }
    int pos = getOffsetConstruibles() + isConstruyendo + tipo;
    return std::stoi(mensaje.substr(pos, porConstruido));
}

int PaqueteFabrica::getOffsetConstruibles() {
    int cantidad = getCantConstuibles();
    return cantidad * (tiempo + tipo) + posCant + cant;
}

int PaqueteFabrica::getCantConstuibles() {
    return std::stoi(mensaje.substr(posCant, cant));;
}


