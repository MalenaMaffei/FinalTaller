#include "VistaBandera.h"
#define HEIGHT 32
#define WIDTH 24
#define CLIPS 4
VistaBandera::VistaBandera(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                         HEIGHT,
                                                         WIDTH,
                                                         CLIPS,
                                                         banderaPath) {}
