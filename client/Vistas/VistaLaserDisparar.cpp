#include "../Header Files/VistaLaserDisparar.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 24
#define LARGO_ANIMACION 3
VistaLaserDisparar::VistaLaserDisparar(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS,
                        LARGO_ANIMACION,
                        robotLaserDisparar) {}
