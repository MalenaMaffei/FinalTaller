#ifndef TPFINAL_ICONOVEHICULO_H
#define TPFINAL_ICONOVEHICULO_H

#include "GuiGallery.h"
#include "PaqueteUnidad.h"
class VehiculoGallery : public GuiGallery {
 public:
  VehiculoGallery(Vista *vista,Punto relPos);
  void setInfo(PaqueteUnidad paquete);
  void mostrar();
 private:
//  enum posLabels {
//    labelHeavy = 0,
//    labelJeep = 1,
//    labelLight = 2,
//    labelMedium = 3,
//    labelMissile = 4
//  };
//  std::map<int, int> labels;
};

#endif //TPFINAL_ICONOVEHICULO_H
