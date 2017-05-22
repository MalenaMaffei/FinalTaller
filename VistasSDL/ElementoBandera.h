#ifndef TPFINAL_ELEMENTOBANDERA_H
#define TPFINAL_ELEMENTOBANDERA_H

#include "Elemento.h"
class ElementoBandera : public Elemento {
 public:
  ElementoBandera(int id, int x, int y, Vista *textura);
  void mostrar(Camara &camera);



};

#endif //TPFINAL_ELEMENTOBANDERA_H
