#ifndef TPFINAL_CAMARA_H
#define TPFINAL_CAMARA_H
#include <SDL2/SDL.h>
#include "Texture.h"
#include "constantes.h"
#include "Punto.h"
#include "Rect.h"
//TODO meter mostrar del background en camara? ver como esta hecho en tiles
class Camara {
 public:
  static const int CAM_VEL = 700;
  explicit Camara();

  void handleEvent(SDL_Event& e);

  void move(float timeStep);

  int getCamaraX();
  int getCamaraY();
  Punto getOffset();
  SDL_Rect* getCamara();

  bool checkCollision(Rect b);
 private:
    Rect mBox;

  float mVelX, mVelY;
};

#endif //TPFINAL_CAMARA_H
