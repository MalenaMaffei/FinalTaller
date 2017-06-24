#include "../Header Files/VistaIconoRobot.h"
#define WIDTH 86
#define HEIGHT 72
#define CLIPS 6
VistaIconoRobot::VistaIconoRobot(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                              HEIGHT,
                                                              WIDTH,
                                                              CLIPS,
                                                              carasPath,
                                                              COLORES) {}
