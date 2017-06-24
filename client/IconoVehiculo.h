#ifndef TPFINAL_ICONOVEHICULO_H
#define TPFINAL_ICONOVEHICULO_H

#include "ElementoGui.h"
class IconoVehiculo : public ElementoGui {
 public:
  IconoVehiculo(SDL_Renderer *gRenderer);
  void setInfo(Paquete paquete);
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

#endif //TPFINAL_ICONOVEHICULO_H
