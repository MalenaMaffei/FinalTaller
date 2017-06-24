#ifndef TPFINAL_ICONOROBOT_H
#define TPFINAL_ICONOROBOT_H

#include "ElementoGui.h"
class IconoRobot  : public ElementoGui{
 public:
  IconoRobot(SDL_Renderer *gRenderer);
  void setInfo(Paquete paquete);
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

#endif //TPFINAL_ICONOROBOT_H
