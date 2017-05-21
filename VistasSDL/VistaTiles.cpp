#include "VistaTiles.h"
#define TILE_SIZE 16
#define CLIPS 3

VistaTiles::VistaTiles(SDL_Renderer *gRenderer,const std::string &fileName) :
    Vista(gRenderer,TILE_SIZE,TILE_SIZE,CLIPS,fileName) {}

void VistaTiles::mostrar(int x, int y, int clip) {
    render(x, y, &gClips[clip]);
}
