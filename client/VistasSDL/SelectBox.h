#ifndef TPFINAL_SELECTBOX_H
#define TPFINAL_SELECTBOX_H
#include <SDL2/SDL.h>
#include <vector>
#include "ElementoUnidad.h"

//class ElementoUnidad;
class SelectBox {

   public:
  SelectBox();

  void mostrar(SDL_Renderer *renderer);
  int getX();
  int getY();

  bool checkCollision(SDL_Rect b );
  void setRect(const SDL_Rect &rect);
  void selectUnidad(ElementoUnidad &unidad);
  void vaciarSeleccionadas();
  bool haySeleccion();

 private:
  SDL_Rect rect;

  std::vector<ElementoUnidad> seleccionadas;
};

#endif //TPFINAL_SELECTBOX_H
