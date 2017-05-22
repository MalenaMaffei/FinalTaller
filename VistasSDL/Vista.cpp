#include "Vista.h"
#include "VistaAnimada.h"


Vista::Vista(SDL_Renderer *gRenderer,
             int height,
             int width,
             int clips,
             std::string fileName)
    : LTexture(gRenderer), height(height), width(width), clips(clips),
      fileName(fileName){
    loadMedia();
}

bool Vista::loadMedia() {
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
//    TODO sacar ruta y ponerla en un .h
    printf( "justo antes de cargar\n" );
    if( !loadFromFile(fileName) ){
        printf( "Failed to load tile texture!\n" );
        success = false;
        return success;
    }

    else{

        int col = 0;
        for (size_t j = 0; j < clips; j++) {
            SDL_Rect rect;
            rect.x  =   col;
            rect.y = 0;
            rect.w = width;
            rect.h = height;
            gClips.push_back(rect);

            col += width;
        }
    }
    printf( "al final de cargar\n" );
    return success;
}

Vista::~Vista() {
//gSpriteSheetTextureTank.free(); TODO no se si hay que ponerlo
}
void Vista::mostrar(int x, int y, int nrClip) {
    render(x, y, &gClips[nrClip%clips]);
}


