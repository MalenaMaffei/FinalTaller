#include "VistaHudCaras.h"
#define WIDTH 86
#define HEIGHT 72
#define CLIPS 1
VistaHudCaras::VistaHudCaras(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                              HEIGHT,
                                                              WIDTH,
                                                              CLIPS,
                                                              carasPath) {}
