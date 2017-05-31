#include "../Header Files/VistaDireccionada.h"
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
    fileName), largoAnimacion(largoAnimacion) {}

int VistaDireccionada::getLargoAnimacion() const {
    return largoAnimacion;
}

int VistaDireccionada::getClip(int clip, int direccion) const {
    clip = clip%largoAnimacion;
    clip = clip + (direccion*largoAnimacion);
    return clip;
}
