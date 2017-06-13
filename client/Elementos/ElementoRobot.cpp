#include "../Header Files/ElementoRobot.h"
ElementoRobot::ElementoRobot(std::string id,
                             int x,
                             int y,
                             VistaDireccionada *texturaCaminar,
                             VistaDireccionada *texturaDisparar,
                             Vista *vistaMuerte,
                             bool esMio) :
    ElementoUnidad(id, x, y, texturaCaminar, texturaDisparar,
                   vistaMuerte, esMio, 0)
//    , texturaDisparar(texturaDisparar)
//    , currentVista(texturaCaminar)
{}
