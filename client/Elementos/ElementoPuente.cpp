#include "../Header Files/ElementoPuente.h"
#include <string>
#define HEIGHT 64
#define WIDTH 64
ElementoPuente::ElementoPuente(std::string id,
                               int x,
                               int y,
                               Vista *textura,
                               bool vertical) : Elemento(id,
                                                         x,
                                                         y,
                                                         textura,
                                                         false) {
    if (vertical){
        currentClip = 2;
    }
}
