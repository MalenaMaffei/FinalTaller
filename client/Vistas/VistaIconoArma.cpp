#include "../Header Files/VistaIconoArma.h"
#define WIDTH 100
#define HEIGHT 101
#define CLIPS 6
VistaIconoArma::VistaIconoArma(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                                HEIGHT,
                                                                WIDTH,
                                                                CLIPS,
                                                                armasPath) {}
