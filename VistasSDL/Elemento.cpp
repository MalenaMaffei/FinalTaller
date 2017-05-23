#include "Elemento.h"
Elemento::Elemento(int id,
                   int x,
                   int y,
                   Vista *textura)
    : textura(textura), id(id), currentClip(0) {
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = textura->getWidth();
    mBox.h = textura->getHeight();
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

bool Elemento::estaMuerto() const {
    return muerto;
}
void Elemento::matar() {
    return;
}
