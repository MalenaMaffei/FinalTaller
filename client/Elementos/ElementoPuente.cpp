#include "../Header Files/ElementoPuente.h"
#include <string>
#define HEIGHT 64
#define WIDTH 64
ElementoPuente::ElementoPuente(std::string id,Punto pos,Vista *textura,
                               bool vertical) : Elemento(id,pos,textura,false) {
    if (vertical){
        currentClip = 2;
    }
}
