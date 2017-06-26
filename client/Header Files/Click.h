#ifndef TPFINAL_CLICK_H
#define TPFINAL_CLICK_H

#include "Elemento.h"
class Click {
 public:
  Click();

  void setPunto(Punto punto);

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
  const Punto &getScreenCoords() const;
  void setScreenCoords(const Punto &screenCoords);

 private:
  Elemento* clicked;
  Punto coords;
  Punto screenCoords;
  bool seleccion;
};

#endif //TPFINAL_CLICK_H
