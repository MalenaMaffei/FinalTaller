#include "ElementoPuente.h"
#define HEIGHT 64
#define WIDTH 64
ElementoPuente::ElementoPuente(int id,
                               int x,
                               int y,
                               Vista *textura,
                               bool vertical) : Elemento(id, x, y, textura) {
    if (vertical){
        currentClip = 2;
    }
}
