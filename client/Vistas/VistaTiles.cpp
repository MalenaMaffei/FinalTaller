#include "../Header Files/VistaTiles.h"
#include "../Header Files/constantes.h"
//#define TILE_SIZE 16
//#define CLIPS 4

VistaTiles::VistaTiles(SDL_Renderer *gRenderer) :
    Vista(gRenderer, TILE_WIDTH, TILE_HEIGHT, TILE_CLIPS, tilePath) {}

//void VistaTiles::mostrar(int x, int y, int clip) {
//    render(x, y, &gClips[clip]);
//}
