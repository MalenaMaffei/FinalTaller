#include "../Header Files/VistaLabelRobot.h"
#define WIDTH 96
#define HEIGHT 14
#define CLIPS 6
VistaLabelRobot::VistaLabelRobot(SDL_Renderer *gRenderer)
    : Vista(gRenderer,
            HEIGHT,
            WIDTH,
            CLIPS,
            robotsLabelPath) {}
