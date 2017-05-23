#ifndef TPFINAL_ELEMENTOROCA_H
#define TPFINAL_ELEMENTOROCA_H

#include "Elemento.h"
#include "VistaRoca.h"
class ElementoRoca : public Elemento{
 public:
  ElementoRoca(int id, int x, int y, VistaRoca *textura);

};

#endif //TPFINAL_ELEMENTOROCA_H
