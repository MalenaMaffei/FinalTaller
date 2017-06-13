#include "../Header Files/VistaHudRobotLabels.h"
#define WIDTH 96
#define HEIGHT 14
#define CLIPS 6
VistaHudRobotLabels::VistaHudRobotLabels(SDL_Renderer *gRenderer)
    : Vista(gRenderer,
            HEIGHT,
            WIDTH,
            CLIPS,
            robotsLabelPath) {}
