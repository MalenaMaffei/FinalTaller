#include "../Header Files/ElementoBandera.h"
#include <string>
#define HEIGHT 24
#define WIDTH 32
ElementoBandera::ElementoBandera(std::string id, int x, int y, Vista *textura,
                                 int color)
    : ElementoColoreado(id, x, y, textura, false, color) {}

void ElementoBandera::mostrar(Camara &camera) {
    currentClip = textura->getClip(++currentClip);
    ElementoColoreado::mostrar(camera);
}
