#include "../Header Files/VistaLabelVehiculo.h"
#define WIDTH 96
#define HEIGHT 14
#define CLIPS 5
VistaLabelVehiculo::VistaLabelVehiculo(SDL_Renderer *gRenderer)
    : Vista(gRenderer,
            HEIGHT,
            WIDTH,
            CLIPS,
            vehiculosLabelPath) {}
