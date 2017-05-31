#include "../Header Files/VistaBandera.h"
#define HEIGHT 24
#define WIDTH 32
#define CLIPS 4

VistaBandera::VistaBandera(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                         HEIGHT,
                                                         WIDTH,
                                                         CLIPS,
                                                         banderaPath) {}
