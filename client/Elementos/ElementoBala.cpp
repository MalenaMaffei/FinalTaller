#include "../Header Files/ElementoBala.h"
#include <string>
using std::string;
ElementoBala::ElementoBala(string id, int x, int y, Vista *textura)
    : Elemento(id, x, y, textura, false) {}

void ElementoBala::mover(Punto nuevo) {
    rect.setPunto(nuevo);
}

void ElementoBala::matar() {
    muerto = true;
}
