#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H

#include "Vista.h"
//TODO van a faltar las vistas de los bichos
//TODO es la misma para todos, el server me dice que puede construir, dsp
// vemos que hacer con el nombre
class GuiEdificio {
 public:
  GuiEdificio(Vista &vistaGui);
  void mostrar(Punto offset);
  void abrirGui(Punto pos);
  bool click(Punto click);
 private:
  Vista& vistaGui;
  Rect ok;
  Rect cancel;
  Rect next;
  bool seMuestra;
  Punto position;
};

#endif //TPFINAL_GUIEDIFICIO_H