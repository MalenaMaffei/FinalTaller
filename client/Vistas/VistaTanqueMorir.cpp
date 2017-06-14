#include "../Header Files/VistaTanqueMorir.h"
#define HEIGHT 32
#define WIDTH 32
#define CLIPS 7

VistaTanqueMorir::VistaTanqueMorir(SDL_Renderer *gRenderer) :
    Vista(gRenderer, HEIGHT, WIDTH, CLIPS, tanqueMuertePath) {}

