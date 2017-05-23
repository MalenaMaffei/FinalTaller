#define HEIGHT 32
#define WIDTH 32
#define CLIPS 1
#include "constantes.h"
#include "VistaRoca.h"
VistaRoca::VistaRoca(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                      HEIGHT,
                                                      WIDTH,
                                                      CLIPS,
                                                      rocaPath) {}
