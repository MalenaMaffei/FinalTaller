#ifndef TPFINAL_BOTON_H
#define TPFINAL_BOTON_H

#include "Rect.h"
class Boton {
 public:
  Boton(Punto posRel, int w, int h);
  void ubicar(Punto p);
  bool wasPressed(Punto click);
 private:
  Rect botonRelativo;
  Rect botonAbsoluto;
};

#endif //TPFINAL_BOTON_H
