#include "VistaAnimada.h"
#include "Camara.h"

VistaAnimada::VistaAnimada(SDL_Renderer *gRenderer) : LTexture(gRenderer) {

    loadMedia();
    frame = 0;
    currentClip = &gSpriteClips[frame % WALKING_ANIMATION_FRAMES];

}

bool VistaAnimada::loadMedia() {
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
//    TODO sacar ruta y ponerla en un .h
    if( !loadFromFile( "../VistasSDL/imgs/tank.png"
    ) ){
        printf( "Failed to load tank animation texture!\n" );
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

void VistaAnimada::mostrar(Camara &camara) {
    if( camara.checkCollision( objeto ) ) {
        render(x-camara.getCamaraX(), y-camara.getCamaraY(), currentClip);
        avanzarFrame();
    }
}

void VistaAnimada::avanzarFrame() {
    ++frame;
    frame = frame % WALKING_ANIMATION_FRAMES;
    currentClip = &gSpriteClips[frame];
}

VistaAnimada::~VistaAnimada() {
//gSpriteSheetTextureTank.free(); TODO no se si hay que ponerlo
}
