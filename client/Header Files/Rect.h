#ifndef TPFINAL_RECT_H
#define TPFINAL_RECT_H

#include <SDL_rect.h>
#include "Punto.h"

class Rect : public SDL_Rect{
 public:
  Rect(Punto p = Punto(0,0), int width = 0, int height = 0);

//  Devuelve otro Rect con el origen corrido positivamente tantas unidades
// como indique shift
  Rect positiveShift(Punto shift) const;

//  Devuelve otro Rect con el origen corrido negativamente tantas unidades
// como indique shift
  Rect negativeShift(Punto shift) const;

//  Punto esta dentro del Rect?
  bool incluyePunto(Punto p);

//  Rect se toca con otro Rect?
  bool hayColision(Rect otro);

  Punto getPunto() const;

  void setPunto(Punto p);

  Punto getCentro() const;
};

#endif //TPFINAL_RECT_H
