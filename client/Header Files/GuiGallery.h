#ifndef TPFINAL_ELEMENTOGUI_H
#define TPFINAL_ELEMENTOGUI_H
#include <map>
#include "Punto.h"
#include "Vista.h"
#include "PaqueteAccion.h"
#include "PaqueteUnidad.h"
class GuiGallery {
 public:
  GuiGallery(Vista *vista,
              Punto relPos);
  void mostrar(Punto p);
  virtual void setInfo(PaqueteUnidad paquete);
  virtual void setInfo(int tipo);
  virtual ~GuiGallery();

 protected:
  enum posLabels {
    labelGrunt = 0,
    labelLaser = 1,
    labelPsycho = 2,
    labelPyro = 3,
    labelSniper = 4,
    labelTough = 5,
    labelHeavy = 0,
    labelJeep = 1,
    labelLight = 2,
    labelMedium = 3,
    labelMissile = 4
  };
  Vista* vista;
  Punto relPos;
  bool seMuestra;
  int clip;
  CodigosPaquete codigos;
  std::map<int, int> labels;
};

#endif //TPFINAL_ELEMENTOGUI_H
