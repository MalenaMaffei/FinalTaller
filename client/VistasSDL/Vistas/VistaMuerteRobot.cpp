#include "../Header Files/VistaMuerteRobot.h"
#define HEIGHT 16
#define WIDTH 16
#define CLIPS 7
VistaMuerteRobot::VistaMuerteRobot(SDL_Renderer *gRenderer) : Vista(
    gRenderer,
    HEIGHT,
    WIDTH,
    CLIPS,
    robotMuertePath) {}
