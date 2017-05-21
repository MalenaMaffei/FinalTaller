#include "VistaTile.h"
#include "VistaAnimada.h"


VistaTile::VistaTile(SDL_Renderer *gRenderer) : LTexture(gRenderer) {

    loadMedia();
    frame = 0;
    currentClip = &gSpriteClips[frame % WALKING_ANIMATION_FRAMES];
}

bool VistaTile::loadMedia() {
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
//    TODO sacar ruta y ponerla en un .h
    if( !loadFromFile( "../VistasSDL/imgs/ciudadTiles.png"
    ) ){
        printf( "Failed to load tile texture!\n" );
        success = false;
        return success;
    }

    else{
        int col = 0;
        for (size_t j = 0; j < 3; j++) {
            gSpriteClips[ j ].x =   col;
            gSpriteClips[ j ].y =   0;
            gSpriteClips[ j ].w =  width;
            gSpriteClips[ j ].h =  height;

            col += width;
        }
    }

    return success;
}

void VistaTile::mostrar(int x, int y) {
    render( x, y, currentClip);
    avanzarFrame();
}

Vista::~Vista() {
//gSpriteSheetTextureTank.free(); TODO no se si hay que ponerlo
}
