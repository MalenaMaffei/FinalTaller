#include "../Header Files/VistaRobotMorir.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 7
VistaRobotMorir::VistaRobotMorir(SDL_Renderer *gRenderer) : Vista(
    gRenderer,
    HEIGHT,
    WIDTH,
    CLIPS,
    robotMuertePath) {}
