#ifndef TPFINAL_ELEMENTO_H
#define TPFINAL_ELEMENTO_H

#include <SDL_rect.h>
#include "Vista.h"
class Elemento {
 public:
//  TODO refactorizar la necesidad de pasar width height
  Elemento(int id,
           int x,
           int y,
           Vista *textura);
  virtual void mostrar(Camara &camera);
 protected:
  //The attributes of the tile
  SDL_Rect mBox;

  Vista* textura;
  int id;
  int currentClip;
};

#endif //TPFINAL_ELEMENTO_H
