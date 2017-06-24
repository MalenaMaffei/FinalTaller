#include "../Header Files/ElementoBandera.h"
#include <string>
#define HEIGHT 24
#define WIDTH 32
ElementoBandera::ElementoBandera(std::string id,Punto pos,Vista *textura,
                                 int color)
    : ElementoColoreado(id, pos, textura, false, color) {}

void ElementoBandera::mostrar(Camara &camera) {
    currentClip = textura->getClip(++currentClip);
    ElementoColoreado::mostrar(camera);
}

void ElementoBandera::clicked(Click &click) {
    return;
}
