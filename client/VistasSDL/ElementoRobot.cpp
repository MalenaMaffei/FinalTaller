#include "ElementoRobot.h"
ElementoRobot::ElementoRobot(int id,
                             int x,
                             int y,
                             VistaDireccionada *texturaCaminar,
                             VistaDireccionada *texturaDisparar,
                             Vista *vistaMuerte,
                             bool esMio) :
        ElementoUnidad(id, x, y, texturaCaminar, vistaMuerte, esMio, 0), texturaDisparar(texturaDisparar)
//    , currentVista(texturaCaminar)
{}
