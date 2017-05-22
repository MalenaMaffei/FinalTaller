#include "Elemento.h"
Elemento::Elemento(int id,
                   int x,
                   int y,
                   int width,
                   int height,
                   Vista *textura)
    : textura(textura), id(id), currentClip(0) {
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = width;
    mBox.h = height;
}

void Elemento::mostrar(Camara &camera) {
//    textura->mostrar(mBox.x, mBox.y , mType);
    //If the tile is on screen
    if( camera.checkCollision( mBox ) ){
        //Show the tile

        textura->mostrar(mBox.x - camera.getCamaraX(),
                         mBox.y - camera.getCamaraY(),
                         currentClip);
//        gTileTexture.render( mBox.x - camera.x, mBox.y - camera.y, &gTileClips[ mType ] );
    }
}
