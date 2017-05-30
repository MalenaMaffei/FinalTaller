#ifndef TPFINAL_COLECTORDEACCIONES_H
#define TPFINAL_COLECTORDEACCIONES_H

#include "SelectBox.h"
#include "Click.h"
#include "Hud.h"
#include "GuiEdificio.h"
class ColectorDeAcciones {
 public:
  ColectorDeAcciones(SelectBox &selectBox,
                       Click &click,
                       Hud &hud,
                       GuiEdificio &guiEdificio);

  void crearAcciones();
  void showHud();
  void showEdificio();

 private:
  SelectBox &selectBox;
  Click &click;
  GuiEdificio &guiEdificio;
  Hud &hud;
};

#endif //TPFINAL_COLECTORDEACCIONES_H
