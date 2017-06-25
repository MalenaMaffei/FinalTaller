#ifndef TPFINAL_VISTATILE_H
#define TPFINAL_VISTATILE_H
#include <vector>
#include <string>
#include "Texture.h"
#include "Camara.h"

class Vista : public Texture{
 public:
  Vista(SDL_Renderer *gRenderer,
        int height,
        int width,
        size_t clips,
        std::string fileName,
        size_t filas = 1);
  virtual bool loadMedia();

  virtual void mostrar(Punto p, size_t nrClip);
  virtual ~Vista();
  int getHeight() const;
  int getWidth() const;
  size_t getClip(size_t clip, size_t fila = 0) const;
  virtual bool isLastClip(size_t clip) const;

 protected:
  virtual void recorrerImagen();
  std::vector<SDL_Rect> gClips;

  int height;
  int width;
  size_t clips;
  std::string fileName;
  size_t filas;
};

#endif //TPFINAL_VISTATILE_H
