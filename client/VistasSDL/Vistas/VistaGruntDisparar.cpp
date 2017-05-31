#include "../Header Files/VistaGruntDisparar.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 40
#define LARGO_ANIMACION 5
VistaGruntDisparar::VistaGruntDisparar(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS,
                        LARGO_ANIMACION,
                        robotGruntDisparar) {}
