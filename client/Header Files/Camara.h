#ifndef TPFINAL_CAMARA_H
#define TPFINAL_CAMARA_H
#include <SDL2/SDL.h>
#include "Texture.h"
#include "constantes.h"
#include "Punto.h"
#include "Rect.h"
class Camara {
 public:
  static const int CAM_VEL = 700;
  explicit Camara();

//  Chequea si el evento es w, a, s, d y setea direccion y velocidad del
// movimiento
  void handleEvent(SDL_Event& e);

//  Mueve la camara con la velocidad y direccion seteadas por handleEvent.
  void move(float timeStep);

  int getCamaraX();
  int getCamaraY();
  Punto getOffset();
  SDL_Rect* getCamara();

//  Chequea si el Rect pasado esta dentro de la camara.
  bool checkCollision(Rect b);
 private:
    Rect mBox;

  float mVelX, mVelY;
};

#endif //TPFINAL_CAMARA_H
