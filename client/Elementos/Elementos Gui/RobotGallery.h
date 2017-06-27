#ifndef TPFINAL_ICONOROBOT_H
#define TPFINAL_ICONOROBOT_H

#include "GuiGallery.h"
#include "../../Header Files/PaqueteUnidad.h"
class RobotGallery  : public GuiGallery{
 public:
  RobotGallery(Vista *vista,
                 Punto relPos);
  void setInfo(PaqueteUnidad paquete);
 private:
//  enum posLabels {
//    labelGrunt = 0,
//    labelLaser = 1,
//    labelPsycho = 2,
//    labelPyro = 3,
//    labelSniper = 4,
//    labelTough = 5
//  };
//  std::map<int, int> labels;
};

#endif //TPFINAL_ICONOROBOT_H
