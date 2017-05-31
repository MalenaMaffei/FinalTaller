#include "../Header Files/VistaPsychoDisparar.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 16
#define LARGO_ANIMACION 2
VistaPsychoDisparar::VistaPsychoDisparar(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS,
                        LARGO_ANIMACION,
                        robotPsychoDisparar) {}
