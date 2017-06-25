#include "../Header Files/VistaDireccionada.h"
#include <string>
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

size_t VistaDireccionada::getClip(size_t clip, size_t direccion) const {
    clip = clip%largoAnimacion;
    clip = clip + (direccion*largoAnimacion);
    return clip;
}

bool VistaDireccionada::isLastClip(int clip, int direccion) const {
    clip = clip%largoAnimacion;
    clip = clip + (direccion*largoAnimacion);
    return clip == largoAnimacion-1;
}
