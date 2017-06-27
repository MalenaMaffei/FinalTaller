#include "../Header Files/VistaLabelFabrica.h"
#define WIDTH 60
#define HEIGHT 10
#define CLIPS 3
VistaLabelFabrica::VistaLabelFabrica(SDL_Renderer *gRenderer) :
    Vista(gRenderer, HEIGHT, WIDTH,  CLIPS, fabricaLabelsPath) {}
