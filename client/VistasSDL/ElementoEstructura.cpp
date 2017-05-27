#include "ElementoEstructura.h"
ElementoEstructura::ElementoEstructura(int id,
                                       int x,
                                       int y,
                                       Vista *textura,
                                       bool esMio) : Elemento(id,
                                                              x,
                                                              y,
                                                              textura,
                                                              esMio) {}
