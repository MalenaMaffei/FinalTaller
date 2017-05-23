#include "ElementoBandera.h"
#define HEIGHT 24
#define WIDTH 32
ElementoBandera::ElementoBandera(int id, int x, int y, Vista *textura)
    : Elemento(id, x, y, textura) {}

void ElementoBandera::mostrar(Camara &camera) {
    currentClip = textura->getClip(++currentClip);
    Elemento::mostrar(camera);
}
