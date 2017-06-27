    #include "../Header Files/ElementoColoreado.h"
#include <string>
ElementoColoreado::ElementoColoreado(std::string id,Punto pos,Vista *textura,
                                     bool esMio,
                                     int color) :
    Elemento(id, pos, textura, esMio), color(color) {}


void ElementoColoreado::mostrar(Camara &camera) {
    currentClip = textura->getClip(currentClip,color);
    Elemento::mostrar(camera);
}
