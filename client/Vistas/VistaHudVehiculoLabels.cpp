#include "../Header Files/VistaHudVehiculoLabels.h"
#define WIDTH 96
#define HEIGHT 14
#define CLIPS 5
VistaHudVehiculoLabels::VistaHudVehiculoLabels(SDL_Renderer *gRenderer)
    : Vista(gRenderer,
            HEIGHT,
            WIDTH,
            CLIPS,
            vehiculosLabelPath) {}
