#include "../Header Files/VistaMissilelauncher.h"
#define HEIGHT 30
#define WIDTH 32
#define CLIPS 24
#define LARGO_ANIMACION 3
VistaMissilelauncher::VistaMissilelauncher(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS,
                        LARGO_ANIMACION,
                        tanqueMissilePath) {}
