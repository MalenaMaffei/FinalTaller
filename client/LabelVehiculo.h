#ifndef TPFINAL_LABELTANQUE_H
#define TPFINAL_LABELTANQUE_H

#include "ElementoGui.h"
class LabelVehiculo : public ElementoGui  {
 public:
  LabelVehiculo(SDL_Renderer *gRenderer);
  void setInfo(PaqueteAccion paquete);
  void mostrar();
 private:
  enum posLabels {
    labelHeavy = 0,
    labelJeep = 1,
    labelLight = 2,
    labelMedium = 3,
    labelMissile = 4
  };
  std::map<int, int> labels;
};

#endif //TPFINAL_LABELTANQUE_H
