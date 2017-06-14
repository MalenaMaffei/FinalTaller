#include "../Header Files/VistaFabricaRobot.h"
#include "../Header Files/constantes.h"
#define CLIPS 3
#define HEIGHT 80
#define WIDTH 80
VistaFabricaRobot::VistaFabricaRobot(SDL_Renderer *gRenderer) :
    Vista(gRenderer, HEIGHT, WIDTH, CLIPS, fabricaRobotsPath, COLORES) {}
