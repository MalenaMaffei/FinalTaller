#ifndef TPFINAL_VISTADIRECCIONADA_H
#define TPFINAL_VISTADIRECCIONADA_H

#include "Vista.h"
#include <string>
class VistaDireccionada : public Vista{
//  Estas vistas son las que usan los robots y tanques para caminar y
// disparar, son direcciondas porque el clip que se va a usar va a depender
// de la direccion que tenga la undidad
 public:
  VistaDireccionada(SDL_Renderer *gRenderer,
                      int height,
                      int width,
                      int clips,
                      int largoAnimacion,
                      const std::string &fileName);
//  void mostrar(int x, int y, int nrClip, int direccion);
  int getLargoAnimacion() const;
//  Devuelve el numero de clip que le sigue al pasado teniendo en cuenta la
// direccion que tiene
  size_t getClip(size_t clip, size_t direccion) const;
  virtual bool isLastClip(int clip, int direccion) const;
 protected:
  int largoAnimacion;
};

#endif //TPFINAL_VISTADIRECCIONADA_H
