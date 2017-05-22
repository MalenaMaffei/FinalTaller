#include "ElementoRoca.h"
#include "VistaRoca.h"
#define WIDTH 32
#define HEIGHT 32
ElementoRoca::ElementoRoca(int id, int x, int y, VistaRoca *textura)
    : Elemento(id,x,y,WIDTH,HEIGHT,textura) {}
