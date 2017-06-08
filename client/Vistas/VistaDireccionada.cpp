#include "../Header Files/VistaDireccionada.h"
#define COLORES 4
VistaDireccionada::VistaDireccionada(SDL_Renderer *gRenderer,
                                     int height,
                                     int width,
                                     int clips,
                                     int largoAnimacion,
                                     const std::string &fileName) : Vista(
    gRenderer,
    height,
    width,
    clips,
    fileName, COLORES), largoAnimacion(largoAnimacion) {}

int VistaDireccionada::getLargoAnimacion() const {
    return largoAnimacion;
}

int VistaDireccionada::getClip(int clip, int direccion) const {
    clip = clip%largoAnimacion;
    clip = clip + (direccion*largoAnimacion);
    return clip;
}

bool VistaDireccionada::isLastClip(int clip, int direccion) const {
    printf("clip antes: %i, largo animacion: %i\n", clip, largoAnimacion);
    clip = clip%largoAnimacion;
    clip = clip + (direccion*largoAnimacion);
    printf("clip despues: %i\n", clip);
    return clip == largoAnimacion-1 ;
}
