#ifndef TPFINAL_VISTADIRECCIONADA_H
#define TPFINAL_VISTADIRECCIONADA_H

#include "Vista.h"
class VistaDireccionada : public Vista{
 public:
  VistaDireccionada(SDL_Renderer *gRenderer,
                      int height,
                      int width,
                      int clips,
                      int largoAnimacion,
                      const std::string &fileName);
 protected:
  int largoAnimacion;
};

#endif //TPFINAL_VISTADIRECCIONADA_H
