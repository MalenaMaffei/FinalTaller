#include "../Header Files/VistaFuerte.h"
#define CLIPS 2
#define HEIGHT 192
#define WIDTH 160
VistaFuerte::VistaFuerte(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                          HEIGHT,
                                                          WIDTH,
                                                          CLIPS,
                                                          fuertePath) {}
