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

//  Analiza los eventos registrados durante el gamelopp (clicks, selecciones)
// y crea los paquetes correspondientes en respuesta a esas acciones.
  void crearAcciones();

//  Setea al Hud si el click se habia hecho sobre una unidad
  void showHud();

//  Setea al gui de Edificio si el click se habia hecho sobre un edificio
  void showEdificio(std::string id);

 private:
  SelectBox &selectBox;
  Click &click;
  GuiEdificio &guiEdificio;
  Hud &hud;
  ColaPaquetes& colaSalida;
};

#endif //TPFINAL_COLECTORDEACCIONES_H
