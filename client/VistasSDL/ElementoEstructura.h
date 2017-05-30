#ifndef TPFINAL_ELEMENTOESTRUCTURA_H
#define TPFINAL_ELEMENTOESTRUCTURA_H

#include "Elemento.h"
#include "ElementoColoreado.h"

class ElementoEstructura : public ElementoColoreado{
 public:
  ElementoEstructura(int id, int x, int y, Vista *textura,
                       bool esMio, int color);
  void guiRequest(ColectorDeAcciones& colector) const;

};

#endif //TPFINAL_ELEMENTOESTRUCTURA_H
