#ifndef TPFINAL_ELEMENTOFUERTE_H
#define TPFINAL_ELEMENTOFUERTE_H

#include "Elemento.h"
#include "VistaFuerte.h"
class ElementoFuerte : public Elemento {
 public:
  ElementoFuerte(int id, int x, int y, VistaFuerte *textura);
  void matar();
};

#endif //TPFINAL_ELEMENTOFUERTE_H
