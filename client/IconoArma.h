#ifndef TPFINAL_ICONOARMA_H
#define TPFINAL_ICONOARMA_H

#include "ElementoGui.h"
class IconoArma : public ElementoGui{
 public:
  IconoArma(SDL_Renderer *gRenderer);
  void setInfo(PaqueteAccion paquete);
 private:
  enum posLabels {
    labelGrunt = 0,
    labelLaser = 1,
    labelPsycho = 2,
    labelPyro = 3,
    labelSniper = 4,
    labelTough = 5
  };
  std::map<int, int> labels;
};

#endif //TPFINAL_ICONOARMA_H
