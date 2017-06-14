#ifndef TPFINAL_VISTAPROGRESSBAR_H
#define TPFINAL_VISTAPROGRESSBAR_H

#include <SDL_pixels.h>
#include "Rect.h"
class VistaProgressBar {
 public:
  VistaProgressBar(int width,
                     int height,
                     SDL_Renderer *gRenderer,
                     const SDL_Color &FGColor,
                     const SDL_Color &BGColor);
  void llenarHorizontal(float porcentaje, Punto ubicacion);

 private:
  int width;
  int height;
//  Rect barra;
  SDL_Renderer* gRenderer;
  SDL_Color FGColor;
  SDL_Color BGColor;
};

#endif //TPFINAL_VISTAPROGRESSBAR_H
