#ifndef TPFINAL_VISTATILE_H
#define TPFINAL_VISTATILE_H
#include "LTexture.h"

class VistaTile : public LTexture{



 private:
  SDL_Rect gTiles[WALKING_ANIMATION_FRAMES];

//  TODO va a depender de cada vista
  int height = 32;
  int width = 32;
  short frame;
  SDL_Rect* currentClip;
};

#endif //TPFINAL_VISTATILE_H
