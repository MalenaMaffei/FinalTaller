#include "ElementoFuerte.h"
#include "VistaFuerte.h"
#define HEIGHT 192
#define WIDTH 160
ElementoFuerte::ElementoFuerte(int id, int x, int y, VistaFuerte *textura,
                               int color)
    : ElementoEstructura(id, x, y, textura, false, color) {}

void ElementoFuerte::matar() {
    if (!muerto){
        ++currentClip;
    }
}

