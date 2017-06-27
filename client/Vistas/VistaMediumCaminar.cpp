#include "../Header Files/VistaMediumCaminar.h"
#define HEIGHT 32
#define WIDTH 32
#define LARGO_ANIMACION 3
#define CLIPS_TOTAL 24
VistaMediumCaminar::VistaMediumCaminar(SDL_Renderer *gRenderer) :
    VistaDireccionada(gRenderer,HEIGHT,WIDTH,CLIPS_TOTAL,LARGO_ANIMACION,
                      mediumCaminarPath) {}
