#ifndef TPFINAL_VISTATEXTO_H
#define TPFINAL_VISTATEXTO_H
#include <string>
#include "Texture.h"
#include "Punto.h"

class VistaTexto : public Texture {
 public:
  explicit VistaTexto(SDL_Renderer *gRenderer);
  void loadFont(std::string fontPath, int fontSize);
  void mostrar(std::string texto, SDL_Color color, Punto p);
  void closeFont();
  virtual ~VistaTexto();

 private:
  TTF_Font *gFont;
};

#endif //TPFINAL_VISTATEXTO_H
