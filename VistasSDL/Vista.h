#ifndef TPFINAL_VISTA_H
#define TPFINAL_VISTA_H
#include "LTexture.h"
#define WALKING_ANIMATION_FRAMES 3
//TODO esto va en cada vista depende las frames

class Vista : public LTexture{
 public:
  Vista(SDL_Renderer *gRenderer);

//  TODO convertir en void y que lance error
  bool loadMedia();
  void mostrar(int x, int y);
  void avanzarFrame();
  virtual ~Vista();

 protected:
  SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

//  TODO va a depender de cada vista
  int height = 32;
  int width = 32;
  short frame;
  SDL_Rect* currentClip;
};

#endif //TPFINAL_VISTA_H
