#ifndef TPFINAL_RECT_H
#define TPFINAL_RECT_H

#include <SDL_rect.h>
#include "Punto.h"

class Rect : public SDL_Rect{
 public:
  Rect(Punto p = Punto(0,0), int width = 0, int height = 0);
  Rect positiveShift(Punto shift);
  Rect negativeShift(Punto shift);
  bool incluyePunto(Punto p);
  bool hayColision(Rect otro);
  Punto getPunto();
  void setPunto(Punto p);
};

#endif //TPFINAL_RECT_H
