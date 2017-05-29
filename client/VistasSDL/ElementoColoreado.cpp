#include "ElementoColoreado.h"

ElementoColoreado::ElementoColoreado(int id, int x, int y, Vista *textura,
                                     bool esMio, int color) : Elemento(id, x, y,
                                                                       textura,
                                                                       esMio),
                                                              color(color) {}
