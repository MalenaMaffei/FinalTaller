#include "Header Files/ElementoColoreado.h"

ElementoColoreado::ElementoColoreado(std::string id,
                                     int x,
                                     int y,
                                     Vista *textura,
                                     bool esMio,
                                     int color) : Elemento(id, x, y,
                                                                       textura,
                                                                       esMio),
                                                              color(color) {}

void ElementoColoreado::mostrar(Camara &camera) {
//    printf("currclip antes: %i\n", currentClip);
    currentClip = textura->getClip(currentClip,color);
//    printf("currclip dsp: %i\n", currentClip);

    Elemento::mostrar(camera);
}
