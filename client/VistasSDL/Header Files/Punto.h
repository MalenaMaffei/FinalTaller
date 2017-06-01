#ifndef TPFINAL_PUNTO_H
#define TPFINAL_PUNTO_H

#include <SDL_rect.h>
class Punto : public SDL_Point{
 public:
  Punto(int x = 0, int y = 0);
  Punto operator+(Punto otro);
  Punto operator-(Punto otro);

};

#endif //TPFINAL_PUNTO_H
