#include "Header Files/ElementoColoreado.h"

ElementoColoreado::ElementoColoreado(std::string id,
                                     int x,
                                     int y,
                                     Vista *textura,
                                     bool esMio,
                                     int color) : Elemento(id, x, y,
                                                                       textura,
                                                                       esMio),
                                                              color(color) {}
