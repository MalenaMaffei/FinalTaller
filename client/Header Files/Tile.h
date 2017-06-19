#ifndef TPFINAL_TILE_H
#define TPFINAL_TILE_H
#include "VistaTiles.h"
#include "Camara.h"
class Tile {
   public:
    Tile(int x, int y, int tileType, VistaTiles *textura);

    void mostrar(Camara &camera);

    int getType();

    SDL_Rect getBox();

   private:
    Rect mBox;
    int mType;
    VistaTiles* textura;
};

#endif //TPFINAL_TILE_H
