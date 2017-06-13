#include "../Header Files/ElementoTanque.h"
#include "../Header Files/VistaTanqueMorir.h"
ElementoTanque::ElementoTanque(std::string id,
                               int x,
                               int y,
                               VistaDireccionada *textura,
                               Vista *texturaMuerte,
                               bool esMio)
    : ElementoUnidad(id, x, y, textura, nullptr, texturaMuerte, false, 0) {}

