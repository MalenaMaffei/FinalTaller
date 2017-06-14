#ifndef TPFINAL_TILE_H
#define TPFINAL_TILE_H
#include "VistaTiles.h"
#include "Camara.h"
class Tile {
   public:
    //Initializes position and type
    Tile(int x, int y, int tileType, VistaTiles *textura);

    //Shows the tile
    void mostrar(Camara &camera);

    //Get the tile type
    int getType();

    //Get the collision box
    SDL_Rect getBox();

   private:
    //The attributes of the tile
    Rect mBox;

    //The tile type
    int mType;

    VistaTiles* textura;
};

#endif //TPFINAL_TILE_H
