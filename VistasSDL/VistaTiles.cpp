#include "VistaTiles.h"
#include "constantes.h"
#define TILE_SIZE 16
#define CLIPS 3

VistaTiles::VistaTiles(SDL_Renderer *gRenderer) :
    Vista(gRenderer,TILE_SIZE,TILE_SIZE,CLIPS,tilePath) {}

void VistaTiles::mostrar(int x, int y, int clip) {
    render(x, y, &gClips[clip]);
}
