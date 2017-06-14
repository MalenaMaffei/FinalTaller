#ifndef TPFINAL_ELEMENTOBANDERA_H
#define TPFINAL_ELEMENTOBANDERA_H
#include <string> 
#include "Elemento.h"
#include "ElementoColoreado.h"

class ElementoBandera : public ElementoColoreado {
 public:
  ElementoBandera(std::string id, int x, int y, Vista *textura,
                  int color);
  void mostrar(Camara &camera);
};

#endif //TPFINAL_ELEMENTOBANDERA_H
