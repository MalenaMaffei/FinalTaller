#ifndef TPFINAL_HUD_H
#define TPFINAL_HUD_H
#include "Vista.h"
class Hud {
 public:
  Hud(Vista &hud, Vista &vistaCaras);
  void mostrar();
  void setInfo(int tipo);
 private:
  void mostrarContenido();

  Vista& vistaHud;
  Vista& vistaCaras;
  Rect hudRect;
//  int x, y;
  Punto ubicacion;
  int tipoCara;
  bool seleccionado;
  int aMostrar;
  enum posibilidades{
    cara = 0,
    tanque = 1,
    caraYtanque = 2
  };
};

#endif //TPFINAL_HUD_H
