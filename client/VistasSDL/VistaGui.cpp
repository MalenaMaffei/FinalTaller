#include "VistaGui.h"
#include "constantes.h"
#define WIDTH 112
#define HEIGHT 80
#define CLIPS 1
VistaGui::VistaGui(SDL_Renderer *gRenderer) : Vista(gRenderer,
                                                    HEIGHT,
                                                    WIDTH,
                                                    CLIPS,
                                                    guiEdificioPath) {}
