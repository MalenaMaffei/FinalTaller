#include "VistaDireccionada.h"
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
