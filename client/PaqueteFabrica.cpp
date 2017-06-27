#include "Header Files/PaqueteFabrica.h"
#include <map>
#include <string>
using std::string;
PaqueteFabrica::PaqueteFabrica(const std::string &mensaje) : mensaje(mensaje) {}

string PaqueteFabrica::getId() {
    return mensaje.substr(posId, id);
}

int PaqueteFabrica::getTipoFabrica() {
    return toInt(mensaje.substr(posTipoFabrica, tipo));
}

string PaqueteFabrica::getVidaFabrica() {
    return std::to_string(toInt(mensaje.substr(posVida, vida)));
}

std::map<int,std::string> PaqueteFabrica::getConstruibles() {
    std::map<int,std::string> construibles;
    int cantRecibida = getCantConstuibles();
    int currTipo;
    int currTiempo;
    int pos = posCant+cant;
    int offset;
    for (int i = 0; i < cantRecibida; ++i) {
        offset = (tiempo + tipo)*i;
        currTipo = toInt(mensaje.substr(pos + offset, tipo));
        currTiempo = toInt((mensaje.substr(pos + offset + tipo, tiempo)));

        time_t seconds(currTiempo);
        tm *p = gmtime(&seconds);

//        TODO esta bien formatear aca? Explicar por que tuve que usar esto,
// y ojo que no leak
        char buffer [80];

        strftime(buffer,80,"%M:%S",p);
        string minSec = string(buffer);

        construibles[currTipo] = minSec;
    }
    return construibles;
}

bool PaqueteFabrica::estaConstruyendo() {
    int pos = getOffsetConstruibles();
    return toInt(mensaje.substr(pos, isConstruyendo));
}

int PaqueteFabrica::tipoEnConstruccion() {
    int pos = getOffsetConstruibles() + isConstruyendo;
    return toInt(mensaje.substr(pos, tipo));
}

float PaqueteFabrica::porcentajeConstruido() {
    int pos = getOffsetConstruibles() + isConstruyendo + tipo;
    float construido = toInt(mensaje.substr(pos, porConstruido));
    float cienporciento = 100;
    return construido/cienporciento;
}

int PaqueteFabrica::getOffsetConstruibles() {
    int cantidad = getCantConstuibles();
    return cantidad * (tiempo + tipo) + posCant + cant;
}

int PaqueteFabrica::getCantConstuibles() {
    return toInt(mensaje.substr(posCant, cant));;
}


