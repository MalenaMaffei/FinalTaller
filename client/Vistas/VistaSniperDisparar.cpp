#include "../Header Files/VistaSniperDisparar.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 40
#define LARGO_ANIMACION 5
VistaSniperDisparar::VistaSniperDisparar(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS,
                        LARGO_ANIMACION,
                        robotSniperDisparar) {}
