#ifndef TPFINAL_ELEMENTOFUERTE_H
#define TPFINAL_ELEMENTOFUERTE_H

#include "VistaFuerte.h"
#include "ElementoEstructura.h"
class ElementoFuerte : public ElementoEstructura {
 public:
  ElementoFuerte(int id, int x, int y, VistaFuerte *textura,
                   int color);
  void matar();
};

#endif //TPFINAL_ELEMENTOFUERTE_H
