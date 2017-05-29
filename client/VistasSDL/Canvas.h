#ifndef TPFINAL_CANVAS_H
#define TPFINAL_CANVAS_H
#include <SDL_render.h>
#include "common_Thread.h"

class Canvas : public Thread{
 public:
  void init();
  void close();
  void run();
  void gameLoop();

 private:
  //The window we'll be rendering to
  SDL_Window* gWindow;

//The window renderer
  SDL_Renderer* gRenderer;
};

#endif //TPFINAL_CANVAS_H
