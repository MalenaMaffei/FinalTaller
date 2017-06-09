#include "VistaColoreada.h"
VistaColoreada::VistaColoreada(SDL_Renderer *gRenderer,
                               int height,
                               int width,
                               int clips,
                               const std::string &fileName,
                               int cantColores) : Vista(gRenderer,
                                                        height,
                                                        width,
                                                        clips,
                                                        fileName,
                                                        cantColores),
                                                  cantColores(cantColores) {}

//void VistaColoreada::mostrar(Punto ubicacion, int nrClip) {
//    Vista::mostrar(ubicacion, nrClip + (color * clips));
//}

void VistaColoreada::recorrerImagen() {
    printf("hola entre al recorrer del coloreado");
    int col = 0;
    for (size_t i = 0; i < cantColores; ++i) {
        for (size_t j = 0; j < clips; j++) {
            SDL_Rect rect;
            rect.x  = col;
            rect.y = i*height;
            rect.w = width;
            rect.h = height;
            gClips.push_back(rect);

            col += width;
        }
    }
}