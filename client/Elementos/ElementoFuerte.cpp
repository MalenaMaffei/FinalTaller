#include "../Header Files/ElementoFuerte.h"
#include "../Header Files/VistaFuerte.h"
#include <string>
#define HEIGHT 192
#define WIDTH 160
ElementoFuerte::ElementoFuerte(std::string id,
                               int x,
                               int y,
                               Vista *textura,
                               bool esMio,
                               int color)
    : ElementoEstructura(id, x, y, textura, esMio, color) {}

//void ElementoFuerte::matar() {
//    if (!muerto){
//        ++currentClip;
//        muerto = true;
//    }
//}

