#ifndef TPFINAL_ELEMENTOPUENTE_H
#define TPFINAL_ELEMENTOPUENTE_H

#include "Elemento.h"
class ElementoPuente : public Elemento {
 public:
  ElementoPuente(int id,
                   int x,
                   int y,
                   Vista *textura,
                   bool vertical=false);

};

#endif //TPFINAL_ELEMENTOPUENTE_H
