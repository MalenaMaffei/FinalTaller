#include "../Header Files/VistaBala.h"
#include "../Header Files/constantes.h"
#define HEIGHT 5
#define WIDTH 5
#define CLIPS 1

VistaBala::VistaBala(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                      HEIGHT,
                                                      WIDTH,
                                                      CLIPS,
                                                      balaPath) {}
