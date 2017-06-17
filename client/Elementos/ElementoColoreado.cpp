    #include "../Header Files/ElementoColoreado.h"
#include <string>
ElementoColoreado::ElementoColoreado(std::string id,int x,int y,Vista *textura,
                                     bool esMio,int color) :
    Elemento(id, x, y,textura,esMio),color(color) {}

void ElementoColoreado::mostrar(Camara &camera) {
    currentClip = textura->getClip(currentClip,color);
    Elemento::mostrar(camera);
}
