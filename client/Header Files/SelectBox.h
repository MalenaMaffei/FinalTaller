#ifndef TPFINAL_SELECTBOX_H
#define TPFINAL_SELECTBOX_H
#include <SDL2/SDL.h>
#include <vector>
#include "ElementoUnidad.h"

//class ElementoUnidad;
class SelectBox {
   public:
  SelectBox();

  void mostrar(SDL_Renderer *renderer, Punto offset);
  int getX();
  int getY();

  bool checkCollision(Rect b);
  void setRect(const Rect &rect);
  void selectUnidad(ElementoUnidad &unidad);
  void vaciarSeleccionadas();
  bool haySeleccion();
  const std::vector<ElementoUnidad> &getSeleccionadas() const;

 private:
  Rect rect;
  std::vector<ElementoUnidad> seleccionadas;
};

#endif //TPFINAL_SELECTBOX_H
