#include "VistaRobotCaminar.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 32
#define LARGO_ANIMACION 4
VistaRobotCaminar::VistaRobotCaminar(SDL_Renderer *gRenderer)
    : VistaDireccionada(gRenderer,
                        HEIGHT,
                        WIDTH,
                        CLIPS,
                        LARGO_ANIMACION,
                        robotCaminarPath) {}
