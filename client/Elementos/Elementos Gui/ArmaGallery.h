#ifndef TPFINAL_ICONOARMA_H
#define TPFINAL_ICONOARMA_H

#include "GuiGallery.h"
#include "../../Header Files/PaqueteUnidad.h"
class ArmaGallery : public GuiGallery{
 public:
  ArmaGallery(Vista *vista,
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

#endif //TPFINAL_ICONOARMA_H
