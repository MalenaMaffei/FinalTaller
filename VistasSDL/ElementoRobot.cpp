#include "ElementoRobot.h"
ElementoRobot::ElementoRobot(int id,
                             int x,
                             int y,
                             VistaDireccionada *texturaCaminar,
                             VistaDireccionada *texturaDisparar,
                             Vista *vistaMuerte) :
    ElementoUnidad(id, x, y, texturaCaminar, vistaMuerte), texturaDisparar(texturaDisparar), currentVista
    (texturaCaminar) {}
