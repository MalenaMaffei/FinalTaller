#ifndef TPFINAL_CLICK_H
#define TPFINAL_CLICK_H

#include "Elemento.h"
class Click {
 public:
  Click();

  void setCoords(int clickedX,int clickedY);

  const Punto & getPoint() const;

//  Se guarda al elemento clickeado.
  void setClicked(Elemento *clicked);

  void setSeleccion(bool seleccion);

//  Se hizo click sobre algun elemento?
  bool hayClickeado();

  void resetCoords();

// Se hizo algun click?
  bool huboClick();

  Elemento *getClicked() const;

 private:
  Elemento* clicked;
  Punto coords;
  bool seleccion;
};

#endif //TPFINAL_CLICK_H
