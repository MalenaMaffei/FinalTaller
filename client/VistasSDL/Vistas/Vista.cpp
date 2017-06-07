#include "../Header Files/Vista.h"


Vista::Vista(SDL_Renderer *gRenderer,
             int height,
             int width,
             int clips,
             std::string fileName,
             int filas)
    : Texture(gRenderer), height(height), width(width), clips(clips),
      fileName(fileName), filas(filas){
    loadMedia();
}

bool Vista::loadMedia() {
    //Loading success flag
    bool success = true;

    //Load sprite sheet texture
    if( !loadFromFile(fileName) ){
        printf( "Failed to load tile texture!\n" );
        success = false;
        return success;
    }

    else{

        recorrerImagen();
//        int col = 0;
//        for (size_t j = 0; j < clips; j++) {
//            SDL_Rect rect;
//            rect.x  =   col;
//            rect.y = 0;
//            rect.w = width;
//            rect.h = height;
//            gClips.push_back(rect);
//
//            col += width;
//        }
    }
    return success;
}

void Vista::recorrerImagen() {
//    int col = 0;

    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < clips; j++) {
            SDL_Rect rect;
            rect.x  = j*width;
            rect.y = i*height;
            rect.w = width;
            rect.h = height;
            gClips.push_back(rect);

//            col += width;
        }
    }
}

Vista::~Vista() {
//gSpriteSheetTextureTank.free(); TODO no se si hay que ponerlo
}

void Vista::mostrar(Punto p, int nrClip) {
    render(p.x, p.y, &gClips[nrClip]);
}

int Vista::getHeight() const {
    return height;
}

int Vista::getWidth() const {
    return width;
}

int Vista::getClip(int clip, int fila) const {
    return clip%clips + (clips*fila);
}
bool Vista::isLastClip(int clip) const {
    return clip == clips-1 ;
}



