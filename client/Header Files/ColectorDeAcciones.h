#ifndef TPFINAL_COLECTORDEACCIONES_H
#define TPFINAL_COLECTORDEACCIONES_H
#include <string> 
#include "SelectBox.h"
#include "Click.h"
#include "Hud.h"
#include "GuiEdificio.h"
#include "ColaPaquetes.h"
class ColectorDeAcciones {
 public:
  ColectorDeAcciones(SelectBox &selectBox,
                       Click &click,
                       Hud &hud,
                       GuiEdificio &guiEdificio,
                       ColaPaquetes &salida);

  void crearAcciones();
  void showHud();
  void showEdificio(std::string id);

 private:
  SelectBox &selectBox;
  Click &click;
  GuiEdificio &guiEdificio;
  Hud &hud;
//  ColaPaquetes& entrada;
  ColaPaquetes& colaSalida;
};

#endif //TPFINAL_COLECTORDEACCIONES_H
