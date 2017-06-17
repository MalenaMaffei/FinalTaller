#include "../Header Files/VistaHudVehiculos.h"
#define WIDTH 96
#define HEIGHT 54
#define CLIPS 5
VistaHudVehiculos::VistaHudVehiculos(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                                      HEIGHT,
                                                                      WIDTH,
                                                                      CLIPS,
                                                                      vehiculosPath,
                                                                      COLORES) {}
