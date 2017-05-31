#include "../Header Files/VistaPuente.h"
#define HEIGHT 64
#define WIDTH 64
#define CLIPS 4

VistaPuente::VistaPuente(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                          HEIGHT,
                                                          WIDTH,
                                                          CLIPS,
                                                          puentePath) {}
