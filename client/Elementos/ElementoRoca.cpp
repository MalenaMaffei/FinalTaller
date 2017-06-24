#include "../Header Files/ElementoRoca.h"
#include "../Header Files/VistaRoca.h"
#include <string>
#define WIDTH 32
#define HEIGHT 32
ElementoRoca::ElementoRoca(std::string id,Punto pos,Vista *textura)
    : Elemento(id, pos, textura, false) {}
