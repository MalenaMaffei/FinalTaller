#ifndef TPFINAL_ELEMENTOBANDERA_H
#define TPFINAL_ELEMENTOBANDERA_H
#include <string> 
#include "Elemento.h"
#include "ElementoColoreado.h"

class ElementoBandera : public ElementoColoreado {
 public:
  ElementoBandera(std::string id,
                    Punto pos,
                    Vista *textura,
                    int color);
  void mostrar(Camara &camera);
  void clicked(Click& click);
};

#endif //TPFINAL_ELEMENTOBANDERA_H
