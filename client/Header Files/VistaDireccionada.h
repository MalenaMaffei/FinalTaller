#ifndef TPFINAL_VISTADIRECCIONADA_H
#define TPFINAL_VISTADIRECCIONADA_H

#include "Vista.h"
#include <string>
class VistaDireccionada : public Vista{
 public:
  VistaDireccionada(SDL_Renderer *gRenderer,
                      int height,
                      int width,
                      int clips,
                      int largoAnimacion,
                      const std::string &fileName);
//  void mostrar(int x, int y, int nrClip, int direccion);
  int getLargoAnimacion() const;
  int getClip(int clip, int direccion) const;
  virtual bool isLastClip(int clip, int direccion) const;
 protected:
  int largoAnimacion;
};

#endif //TPFINAL_VISTADIRECCIONADA_H
