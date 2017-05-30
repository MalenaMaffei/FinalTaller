#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H

#include "Vista.h"
//TODO van a faltar las vistas de los bichos
class GuiEdificio {
 public:
  GuiEdificio(Vista &vistaGui);
  void mostrar(SDL_Point offset);
  void abrirGui(SDL_Point pos);
 private:
  Vista& vistaGui;
  SDL_Rect ok;
  SDL_Rect cancel;
  SDL_Rect next;
  bool seMuestra;
  SDL_Point position;
};

#endif //TPFINAL_GUIEDIFICIO_H
