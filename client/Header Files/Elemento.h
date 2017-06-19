#ifndef TPFINAL_ELEMENTO_H
#define TPFINAL_ELEMENTO_H

#include <SDL_rect.h>
#include "Vista.h"
#include <string>

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
  bool esMio() const;

// Polimorfismo: Depende sobre que elemento se hizo click, ellos saben que
// hacer al respecto.
  virtual void clicked(Click& click);

//  Polimorfismo: Llaman a la gui correspondiente depende que Elemento fue
// clickeado.
  virtual void guiRequest(ColectorDeAcciones& colector) const;

 protected:
  bool Mio;
  bool muerto;
  Rect rect;

  Vista* textura;
  std::string id;
  int currentClip;
};

#endif //TPFINAL_ELEMENTO_H
