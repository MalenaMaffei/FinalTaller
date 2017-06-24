#ifndef TPFINAL_VISTAPROGRESSBAR_H
#define TPFINAL_VISTAPROGRESSBAR_H

#include <SDL_pixels.h>
#include "Rect.h"
#include "Vista.h"
class ProgressBar {
 public:
  ProgressBar(SDL_Renderer *gRenderer,
                const SDL_Color &FGColor,
                const SDL_Color &BGColor,
                Rect barra,
                bool vertical = false);

//  Dibujan una progress bar horizontal o vertical en la ubicacion y con el
// porcentaje lleno pasados.
  void mostrar(Punto offset);
  void setInfo(float porcentaje);
 private:
  void llenarBarra(Punto offset, Rect porcentajeRect);
  void dibujarRect(Rect rect, SDL_Color color);
  void mostrarHorizontal(Punto offset);
  void mostrarVertical(Punto offset);
  float porcentaje;
  Rect barra;
  bool vertical;
  SDL_Renderer* gRenderer;
  SDL_Color FGColor;
  SDL_Color BGColor;
};

#endif //TPFINAL_VISTAPROGRESSBAR_H
