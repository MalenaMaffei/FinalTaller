#include "../Header Files/ElementoBala.h"
#include <string>
using std::string;
ElementoBala::ElementoBala(string id,Punto pos,Vista *textura)
    : Elemento(id, pos, textura, false) {}

void ElementoBala::mover(Punto nuevo) {
    rect.setPunto(nuevo);
}

void ElementoBala::matar() {
    muerto = true;
}

void ElementoBala::clicked(Click &click) {
    return;
}
