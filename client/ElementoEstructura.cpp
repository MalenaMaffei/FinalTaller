#include "Header Files/ElementoEstructura.h"
#include "Header Files/ColectorDeAcciones.h"
#include <string>
ElementoEstructura::ElementoEstructura(std::string id,
                                       int x,
                                       int y,
                                       Vista *textura,
                                       bool esMio,
                                       int color) :
        ElementoColoreado(id,x,y,textura,esMio, color) {}

void ElementoEstructura::guiRequest(ColectorDeAcciones &colector) const {
    colector.showEdificio();
}
