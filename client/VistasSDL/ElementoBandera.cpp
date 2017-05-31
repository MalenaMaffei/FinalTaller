#include "Header Files/ElementoBandera.h"
#define HEIGHT 24
#define WIDTH 32
ElementoBandera::ElementoBandera(int id, int x, int y, Vista *textura,
                                 int color)
    : ElementoColoreado(id, x, y, textura, false, color) {}

void ElementoBandera::mostrar(Camara &camera) {
    currentClip = textura->getClip(++currentClip);
    Elemento::mostrar(camera);
}
