#ifndef TPFINAL_ELEMENTOROCA_H
#define TPFINAL_ELEMENTOROCA_H

#include "Elemento.h"
#include "VistaRoca.h"
#include <string>
class ElementoRoca : public Elemento{
 public:
  ElementoRoca(std::string id,
                 Punto pos,
                 Vista *textura);
};

#endif //TPFINAL_ELEMENTOROCA_H
