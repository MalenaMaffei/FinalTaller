#include "Header Files/ElementoColoreado.h"
#include <string>
ElementoColoreado::ElementoColoreado(std::string id,int x,int y,Vista *textura,
                                     bool esMio,int color) :
    Elemento(id, x, y,textura,esMio),color(color) {
    printf("el id que le llega a color: %s\n", id.c_str());
}

void ElementoColoreado::mostrar(Camara &camera) {
    currentClip = textura->getClip(currentClip,color);
    Elemento::mostrar(camera);
}
