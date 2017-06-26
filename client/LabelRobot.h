#ifndef TPFINAL_LABELSROBOTS_H
#define TPFINAL_LABELSROBOTS_H

#include "Header Files/Vista.h"
#include "ElementoGui.h"
class LabelRobot : public ElementoGui {

 public:
  LabelRobot(SDL_Renderer *gRenderer);
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

#endif //TPFINAL_LABELSROBOTS_H
