#include "Header Files/ElementoFuerte.h"
#include "Header Files/VistaFuerte.h"
#define HEIGHT 192
#define WIDTH 160
ElementoFuerte::ElementoFuerte(int id,
                               int x,
                               int y,
                               Vista *textura,
                               bool esMio,
                               int color)
    : ElementoEstructura(id, x, y, textura, esMio, color) {}

void ElementoFuerte::matar() {
    if (!muerto){
        ++currentClip;
    }
}

