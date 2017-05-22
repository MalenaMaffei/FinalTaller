#include "ElementoBandera.h"
#define HEIGHT 32
#define WIDTH 24
ElementoBandera::ElementoBandera(int id, int x, int y, Vista *textura)
    : Elemento(id,
               x,
               y,
               WIDTH,
               HEIGHT,
               textura){}

void ElementoBandera::mostrar(Camara &camera) {
    ++currentClip;
    Elemento::mostrar(camera);
}
