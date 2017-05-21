#ifndef TPFINAL_CAMARA_H
#define TPFINAL_CAMARA_H
#include <SDL2/SDL.h>
#include "LTexture.h"
#include "constantes.h"
//TODO meter render del background en camara? ver como esta hecho en tiles
class Camara {
 public:
  //The dimensions of the dot
  static const int DOT_WIDTH = 20;
  static const int DOT_HEIGHT = 20;

  //Maximum axis velocity of the dot
  static const int DOT_VEL = 10;

  //Initializes the variables
  explicit Camara();

  //Takes key presses and adjusts the dot's velocity
  void handleEvent( SDL_Event& e );

  //Moves the dot and check collision against tiles
  void move();

  //Centers the camera over the dot
  void setCamera();

  int getCamaraX();
  int getCamaraY();
  SDL_Rect* getCamara();

  //Shows the dot on the screen
  void render(LTexture *dotTexture);
  bool checkCollision(SDL_Rect b );
 private:
  //Collision box of the dot
  SDL_Rect mBox;

  //The velocity of the dot
  int mVelX, mVelY;
  SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };;
};

#endif //TPFINAL_CAMARA_H
