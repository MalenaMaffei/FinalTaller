#ifndef TPFINAL_VISTATILE_H
#define TPFINAL_VISTATILE_H
#include <vector>
#include "Texture.h"
#include "Camara.h"

class Vista : public Texture{
 public:
  Vista(SDL_Renderer *gRenderer,
          int height,
          int width,
          int clips,
          std::string fileName,
          int filas = 1);
  virtual bool loadMedia();

  virtual void mostrar(Punto p, int nrClip);
  virtual ~Vista();
  int getHeight() const;
  int getWidth() const;
  int getClip(int clip, int fila=0) const;
  bool isLastClip(int clip) const;

 protected:
  virtual void recorrerImagen();
  std::vector<SDL_Rect> gClips;

//  TODO va a depender de cada vista
  int height;
  int width;
  int clips;
  int filas;
  std::string fileName;
//  short frame;
//  SDL_Rect* currentClip;
};

#endif //TPFINAL_VISTATILE_H
