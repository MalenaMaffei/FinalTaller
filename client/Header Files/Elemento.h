#ifndef TPFINAL_ELEMENTO_H
#define TPFINAL_ELEMENTO_H

#include <SDL_rect.h>
#include "Vista.h"
//#include "Click.h"
class Click;
class ColectorDeAcciones;
class Elemento {
 public:
  Elemento(std::string id, int x, int y, Vista *textura, bool esMio);
  virtual void mostrar(Camara &camera);
  virtual bool estaMuerto() const;
  virtual void matar();
  const Rect & getRect() const;
  std::string getId() const;
  void clicked(Click& click);
  bool esMio() const;
  virtual void guiRequest(ColectorDeAcciones& colector) const;
 protected:
  //The attributes of the tile
  bool Mio;
  bool muerto;
  Rect rect;

  Vista* textura;
  std::string id;
  int currentClip;
};

#endif //TPFINAL_ELEMENTO_H
