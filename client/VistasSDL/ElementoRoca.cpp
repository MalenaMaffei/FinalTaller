#include "Header Files/ElementoRoca.h"
#include "Header Files/VistaRoca.h"
#define WIDTH 32
#define HEIGHT 32
ElementoRoca::ElementoRoca(std::string id, int x, int y, Vista *textura)
    : Elemento(id, x, y, textura, false) {}
