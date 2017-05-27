#ifndef TPFINAL_ELEMENTOESTRUCTURA_H
#define TPFINAL_ELEMENTOESTRUCTURA_H

#include "Elemento.h"
class ElementoEstructura : public Elemento{
 public:
  ElementoEstructura(int id, int x, int y, Vista *textura, bool esMio);

};

#endif //TPFINAL_ELEMENTOESTRUCTURA_H
