#include "../Header Files/VistaFabricaVehiculo.h"
#define CLIPS 3
#define HEIGHT 80
#define WIDTH 80
#define COLORES 4
VistaFabricaVehiculo::VistaFabricaVehiculo(SDL_Renderer *gRenderer)
    : Vista(gRenderer,
            HEIGHT,
            WIDTH,
            CLIPS,
            fabricaVehiculosPath,
            COLORES) {}
