#ifndef TPFINAL_ELEMENTOPUENTE_H
#define TPFINAL_ELEMENTOPUENTE_H
#include <string> 
#include "Elemento.h"
class ElementoPuente : public Elemento {
 public:
  ElementoPuente(std::string id,
                   Punto pos,
                   Vista *textura,
                   bool vertical);
};

#endif //TPFINAL_ELEMENTOPUENTE_H
