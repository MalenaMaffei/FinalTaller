#include "../Header Files/Vista.h"
#include <string>

Vista::Vista(SDL_Renderer *gRenderer,
             int height,
             int width,
             size_t clips,
             std::string fileName,
             size_t filas)
    : Texture(gRenderer), height(height), width(width), clips(clips),
      fileName(fileName), filas(filas){
    loadMedia();
}

bool Vista::loadMedia() {
    bool success = true;

    if (!loadFromFile(fileName)){
        printf("No se pudo cargar la textura: %s\n", fileName.c_str());
        success = false;
        return success;
    } else {
        recorrerImagen();
    }
    return success;
}

void Vista::recorrerImagen() {
    for (size_t i = 0; i < filas; ++i) {
        for (size_t j = 0; j < clips; j++) {
            SDL_Rect rect;
            rect.x  = j*width;
            rect.y = i*height;
            rect.w = width;
            rect.h = height;
            gClips.push_back(rect);
        }
    }
}

Vista::~Vista() {}

void Vista::mostrar(Punto p, size_t nrClip) {
    render(p.x, p.y, &gClips[nrClip]);
}

int Vista::getHeight() const {
    return height;
}

int Vista::getWidth() const {
    return width;
}

size_t Vista::getClip(size_t clip, size_t fila) const {
    if (fila > filas-1){
        fila = 0;
    }
    return clip%clips + (clips*fila);
}

bool Vista::isLastClip(size_t clip) const {
    return clip + 1 == clips;
}



