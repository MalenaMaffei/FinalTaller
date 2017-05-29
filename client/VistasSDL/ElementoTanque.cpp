#include "ElementoTanque.h"
#include "VistaMuerteTanque.h"
ElementoTanque::ElementoTanque(int id,
                               int x,
                               int y,
                               VistaDireccionada *textura,
                               Vista *texturaMuerte,
                               bool esMio)
    : ElementoUnidad(id, x, y, textura, texturaMuerte, false, 0) {}

