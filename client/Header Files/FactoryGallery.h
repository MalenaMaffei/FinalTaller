#ifndef TPFINAL_FACTORYGALLERY_H
#define TPFINAL_FACTORYGALLERY_H

#include "GuiGallery.h"
class FactoryGallery : public GuiGallery{
 public:
  FactoryGallery(SDL_Renderer *gRenderer, const Punto &relPos);
  void setInfo(int tipo);
 private:
  enum fabricas{
    labelFuerte = 0,
    labelFabRobot = 1,
    labelFabVehiculo = 2
  };
};

#endif //TPFINAL_FACTORYGALLERY_H
