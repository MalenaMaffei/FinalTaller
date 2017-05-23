#ifndef TPFINAL_SELECTBOX_H
#define TPFINAL_SELECTBOX_H
#include <SDL2/SDL.h>

class SelectBox {

   public:
  SelectBox(int x=10, int y=10, int w=10, int h=10, int filled=true);

  void mostrar(SDL_Renderer* renderer);

 private:
  SDL_Rect rect;
};

#endif //TPFINAL_SELECTBOX_H
