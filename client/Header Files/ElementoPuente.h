#ifndef TPFINAL_ELEMENTOPUENTE_H
#define TPFINAL_ELEMENTOPUENTE_H
#include <string> 
#include "Elemento.h"
class ElementoPuente : public Elemento {
 public:
  ElementoPuente(std::string id,
                 int x,
                 int y,
                 Vista *textura,
                 bool vertical = false);
};

#endif //TPFINAL_ELEMENTOPUENTE_H
