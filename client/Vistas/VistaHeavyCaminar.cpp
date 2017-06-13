#include "../Header Files/VistaHeavyCaminar.h"
#define HEIGHT 32
#define WIDTH 32
#define LARGO_ANIMACION 3
#define CLIPS_TOTAL 24
VistaHeavyCaminar::VistaHeavyCaminar(SDL_Renderer *gRenderer) : VistaDireccionada(
    gRenderer,
    HEIGHT,
    WIDTH,
    CLIPS_TOTAL,
    LARGO_ANIMACION,
    heavyCaminarPath) {}
