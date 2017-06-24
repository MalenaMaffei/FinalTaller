#include "../Header Files/VistaIconoVehiculo.h"
#define WIDTH 96
#define HEIGHT 54
#define CLIPS 5
VistaIconoVehiculo::VistaIconoVehiculo(SDL_Renderer *gRenderer) :
    Vista(gRenderer, HEIGHT, WIDTH, CLIPS, vehiculosPath, COLORES) {}
