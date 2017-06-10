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
  //The dimensions of the dot
//  static const int DOT_WIDTH = 20;
//  static const int DOT_HEIGHT = 20;

  //Maximum axis velocity of the dot
//  static const int CAM_VEL = 10;
  static const int CAM_VEL = 700;

  //Initializes the variables
  explicit Camara();

  //Takes key presses and adjusts the dot's velocity
  void handleEvent( SDL_Event& e );

  //Moves the dot and check collision against tiles
//  void move();
  void move(float timeStep);

  //Centers the camera over the dot
//  void setCamera();
//
  int getCamaraX();
  int getCamaraY();
  Punto getOffset();
  SDL_Rect* getCamara();

  bool checkCollision(Rect b);
 private:
  //Collision box of the dot
//  SDL_Rect mBox;
    Rect mBox;

  //The velocity of the dot
//  int mVelX, mVelY;
  float mVelX, mVelY;
//  SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };;
};

#endif //TPFINAL_CAMARA_H
