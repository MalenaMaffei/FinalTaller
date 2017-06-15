#include "Header Files/PaqueteFabrica.h"
#include <map>
#include <string>
using std::string;
using std::stoi;
PaqueteFabrica::PaqueteFabrica(const std::string &mensaje) : mensaje(mensaje) {}


string PaqueteFabrica::getId() {
    return mensaje.substr(posId, id);
}

int PaqueteFabrica::getTipoFabrica() {
    return stoi(mensaje.substr(posTipoFabrica, tipo));
}

string PaqueteFabrica::getVidaFabrica() {
    return std::to_string(stoi(mensaje.substr(posVida, vida)));
//    return mensaje.substr(posVida, vida);
}

std::map<int,std::string> PaqueteFabrica::getConstruibles() {
    std::map<int,std::string> construibles;
    int cantRecibida = getCantConstuibles();
    int currTipo;
    string currTiempo;
    int pos = posCant+cant;
    int offset;
    for (int i = 0; i < cantRecibida; ++i) {
        offset = (tiempo + tipo)*i;
        currTipo = stoi(mensaje.substr(pos + offset, tipo));
        currTiempo = mensaje.substr(pos + offset + tipo, tiempo);
        construibles[currTipo] = currTiempo;
    }
    return construibles;
}

bool PaqueteFabrica::estaConstruyendo() {
    int pos = getOffsetConstruibles();
    return stoi(mensaje.substr(pos, isConstruyendo));
}

int PaqueteFabrica::tipoEnConstruccion() {
//    if (!estaConstruyendo()){
////        TODO lanzar excepcion aca
//    }
    int pos = getOffsetConstruibles() + isConstruyendo;
    return stoi(mensaje.substr(pos, tipo));
}

int PaqueteFabrica::porcentajeConstruido() {
    //    if (!estaConstruyendo()){
////        TODO lanzar excepcion aca
//    }
    int pos = getOffsetConstruibles() + isConstruyendo + tipo;
    return stoi(mensaje.substr(pos, porConstruido));
}

int PaqueteFabrica::getOffsetConstruibles() {
    int cantidad = getCantConstuibles();
    return cantidad * (tiempo + tipo) + posCant + cant;
}

int PaqueteFabrica::getCantConstuibles() {
    return stoi(mensaje.substr(posCant, cant));;
}
const string &PaqueteFabrica::getMensaje() const {
    return mensaje;
}


