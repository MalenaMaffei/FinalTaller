#ifndef TPFINAL_HUD_H
#define TPFINAL_HUD_H
#include "Vista.h"
class Hud {
 public:
  Hud(Vista &hud, Vista &vistaCaras);
  void mostrar();
  void setCara(int tipo);
 private:
  Vista& vistaHud;
  Vista& vistaCaras;
  SDL_Rect hudRect;
  int x, y;
  int tipoCara;
  bool seleccionado;
};

#endif //TPFINAL_HUD_H
