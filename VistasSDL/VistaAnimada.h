#ifndef TPFINAL_VISTA_H
#define TPFINAL_VISTA_H
#include "LTexture.h"
#include "Camara.h"
#define WALKING_ANIMATION_FRAMES 3
//TODO esto va en cada vista depende las frames

class VistaAnimada : public LTexture{
 public:
  VistaAnimada(SDL_Renderer *gRenderer);

//  TODO convertir en void y que lance error
  bool loadMedia();
  void mostrar(Camara &camara);
  void avanzarFrame();
  virtual ~VistaAnimada();

 protected:
  SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

//  TODO va a depender de cada vista
  int height = 32;
  int width = 32;
  int x = 10;
  int y = 10;
  short frame;
  SDL_Rect* currentClip;
  SDL_Rect objeto = {x,y,width, height};
};

#endif //TPFINAL_VISTA_H
