#include "../Header Files/VistaHeavyDisparar.h"
#define HEIGHT 32
#define WIDTH 32
#define LARGO_ANIMACION 1
#define CLIPS_TOTAL 8
VistaHeavyDisparar::VistaHeavyDisparar(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS_TOTAL,
                        LARGO_ANIMACION,
                        heavyDispararPath) {}
