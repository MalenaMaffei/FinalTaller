#ifndef TPFINAL_VISTATILE_H
#define TPFINAL_VISTATILE_H
#include <vector>
#include "LTexture.h"

class Vista : public LTexture{
 public:
  Vista(SDL_Renderer *gRenderer,
          int height,
          int width,
          int clips,
          std::string fileName);
  virtual bool loadMedia();
//  virtual void mostrar(int x, int y) = 0;
  virtual ~Vista();

 protected:
  std::vector<SDL_Rect> gClips;

//  TODO va a depender de cada vista
  int height;
  int width;
  int clips;
  std::string fileName;
//  short frame;
//  SDL_Rect* currentClip;
};

#endif //TPFINAL_VISTATILE_H