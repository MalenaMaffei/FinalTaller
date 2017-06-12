#ifndef TPFINAL_VISTACOLOREADA_H
#define TPFINAL_VISTACOLOREADA_H

#include "Vista.h"

class VistaColoreada : public Vista {
 public:
    VistaColoreada(SDL_Renderer *gRenderer,
                    int height,
                     int width,
                     int clips,
                     const std::string &fileName,
                     int cantColores);
//    virtual void mostrar(Punto ubicacion, int nrClip);
 protected:
  virtual void recorrerImagen();
  int cantColores;
};

#endif //TPFINAL_VISTACOLOREADA_H
