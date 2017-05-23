#include "ElementoFuerte.h"
#include "VistaFuerte.h"
#define HEIGHT 192
#define WIDTH 160
ElementoFuerte::ElementoFuerte(int id, int x, int y, VistaFuerte *textura)
    : Elemento(id, x, y, textura) {}

void ElementoFuerte::matar() {
    if (!muerto){
        ++currentClip;
    }
}

