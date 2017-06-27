#include "../Header Files/Tile.h"
#define TILE_SIZE 16

Tile::Tile(int x, int y, int tileType, VistaTiles *textura) : mType(tileType)
    , textura(textura) {
    mBox.x = x;
    mBox.y = y;

    mBox.w = TILE_SIZE;
    mBox.h = TILE_SIZE;
}

void Tile::mostrar(Camara &camera){
    if (camera.estaEnfocado(mBox)){
        textura->mostrar(mBox.getPunto() - camera.getPos(), mType);
    }
}

int Tile::getType(){
    return mType;
}

Rect Tile::getRect(){
    return mBox;
}
