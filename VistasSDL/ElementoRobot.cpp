#include "ElementoRobot.h"
ElementoRobot::ElementoRobot(int id, int x, int y,
                             VistaDireccionada *texturaCaminar,
                             VistaDireccionada *texturaDisparar) :
    ElementoUnidad(id, x,y, texturaCaminar), texturaDisparar(texturaDisparar), currentVista
    (texturaCaminar) {}
