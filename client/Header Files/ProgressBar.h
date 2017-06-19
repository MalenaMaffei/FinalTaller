#ifndef TPFINAL_VISTAPROGRESSBAR_H
#define TPFINAL_VISTAPROGRESSBAR_H

#include <SDL_pixels.h>
#include "Rect.h"
#include "Vista.h"
class ProgressBar {
 public:
  ProgressBar(int width,int height,SDL_Renderer *gRenderer,
              const SDL_Color &FGColor,const SDL_Color &BGColor);

//  Dibujan una progress bar horizontal o vertical en la ubicacion y con el
// porcentaje lleno pasados.
  void mostrarHorizontal(float porcentaje, Punto ubicacion);
  void mostrarVertical(float porcentaje, Punto ubicacion);

 private:
  void llenarBarra(Punto ubicacion, Rect porcentajeRect);
  void dibujarRect(Rect rect, SDL_Color color);
  int width;
  int height;
  SDL_Renderer* gRenderer;
  SDL_Color FGColor;
  SDL_Color BGColor;
};

#endif //TPFINAL_VISTAPROGRESSBAR_H
