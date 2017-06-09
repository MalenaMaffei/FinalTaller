#include "Header Files/Tile.h"
#define TILE_SIZE 16

Tile::Tile(int x, int y, int tileType, VistaTiles *textura) : mType(tileType)
    , textura(textura) {
    //Get the offsets
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = TILE_SIZE;
    mBox.h = TILE_SIZE;

    //Get the tile type
//    mType = tileType;
}

void Tile::mostrar(Camara &camera){
//    textura->mostrar(rect.x, rect.y , mType);
    //If the tile is on screen
    if (camera.checkCollision(mBox)){
        //Show the tile
//        Punto ubicacion = mBox.getPunto() - camera.getOffset();
        textura->mostrar(mBox.getPunto() - camera.getOffset(), mType);
    }
}

int Tile::getType(){
    return mType;
}

SDL_Rect Tile::getBox(){
    return mBox;
}
