#include "../Header Files/VistaHud.h"
#define WIDTH 102
#define HEIGHT 263
#define CLIPS 1
VistaHud::VistaHud(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                    HEIGHT,
                                                    WIDTH,
                                                    CLIPS,
                                                    hudPath) {}
