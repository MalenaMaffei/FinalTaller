#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H

#include "Vista.h"
//TODO van a faltar las vistas de los bichos
//TODO es la misma para todos, el server me dice que puede construir, dsp
// vemos que hacer con el nombre
class GuiEdificio {
 public:
  GuiEdificio(Vista &vistaGui);
  void mostrar(SDL_Point offset);
  void abrirGui(SDL_Point pos);
  bool click(SDL_Point click);
 private:
  Vista& vistaGui;
  SDL_Rect ok;
  SDL_Rect cancel;
  SDL_Rect next;
  bool seMuestra;
  SDL_Point position;
};

#endif //TPFINAL_GUIEDIFICIO_H
