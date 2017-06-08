#ifndef TPFINAL_PUNTO_H
#define TPFINAL_PUNTO_H

#include <SDL_rect.h>
class Punto : public SDL_Point{
 public:
  Punto(int x = 0, int y = 0);
  Punto operator+(Punto otro);
  Punto operator-(Punto otro);
//  TODO un mejor nombre no hay?
  int calcularDireccion(Punto otro);
  enum {
    norte = 2,
    noroeste = 3,
    oeste = 4,
    suroeste = 5,
    sur = 6,
    sureste = 7,
    este = 0,
    noreste = 1,
    centro = 8
  };
};

#endif //TPFINAL_PUNTO_H
