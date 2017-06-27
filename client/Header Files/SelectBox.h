#ifndef TPFINAL_SELECTBOX_H
#define TPFINAL_SELECTBOX_H
#include <SDL2/SDL.h>
#include <vector>
#include "ElementoUnidad.h"

//class ElementoUnidad;
class SelectBox {
   public:
  SelectBox();

//  Muestra el recuadro verde que representa a selectBox y remarca de verde a
// las unidades seleciconadas dentro de ese recuadro.
  void mostrar(SDL_Renderer *renderer, Punto offset);

  bool checkCollision(Rect b);
  void setRect(const Rect &rect);

//  Se pushea a la unidad pasada al vector "seleccionadas"
  void selectUnidad(ElementoUnidad *unidad);

//  Se vacia al vector "seleccionadas"
  void vaciarSeleccionadas();

//  Se selecciono algo?
  bool haySeleccion();

  const std::vector<ElementoUnidad*> &getSeleccionadas() const;

 private:
  Rect rect;
  std::vector<ElementoUnidad* > seleccionadas;
};

#endif //TPFINAL_SELECTBOX_H
