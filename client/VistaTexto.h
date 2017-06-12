#ifndef TPFINAL_VISTATEXTO_H
#define TPFINAL_VISTATEXTO_H

#include "Header Files/Texture.h"
#include "Header Files/Punto.h"

class VistaTexto : public Texture {
 public:
  VistaTexto(SDL_Renderer *gRenderer);
  bool loadFont(std::string fontPath, int fontSize);
  void mostrar(std::string texto, SDL_Color color, Punto p);
  virtual ~VistaTexto();
 private:
  TTF_Font *gFont;
};

#endif //TPFINAL_VISTATEXTO_H
