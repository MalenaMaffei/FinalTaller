#ifndef TPFINAL_ELEMENTOTANQUE_H
#define TPFINAL_ELEMENTOTANQUE_H

#include "ElementoUnidad.h"
#include "VistaTanqueMorir.h"
class ElementoTanque : public ElementoUnidad {
 public:
  ElementoTanque(std::string id,
                 int x,
                 int y,
                 VistaDireccionada *textura,
                 Vista *texturaMuerte,
                 bool esMio);


 private:


};

#endif //TPFINAL_ELEMENTOTANQUE_H
