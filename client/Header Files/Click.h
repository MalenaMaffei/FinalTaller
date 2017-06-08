#ifndef TPFINAL_CLICK_H
#define TPFINAL_CLICK_H

#include "Elemento.h"
class Click {
 public:
  Click();
  void setCoords(int clickedX,int clickedY);
  const Punto & getPoint() const;
  void setClicked(Elemento *clicked);
  void setSeleccion(bool seleccion);
  bool hayClickeado();
  void resetCoords();
  bool huboClick();
  Elemento *getClicked() const;

 private:
  Elemento* clicked;
  Punto coords;
  bool seleccion;
//  int x;
//  int y;
};

#endif //TPFINAL_CLICK_H
