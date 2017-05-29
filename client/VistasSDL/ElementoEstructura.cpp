#include "ElementoEstructura.h"
ElementoEstructura::ElementoEstructura(int id, int x, int y, Vista *textura,
                                       bool esMio, int color) :
        ElementoColoreado(id,x,y,textura,esMio, color) {}
