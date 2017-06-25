#ifndef TPFINAL_ELEMENTO_H
#define TPFINAL_ELEMENTO_H

#include <SDL_rect.h>
#include "Vista.h"
#include <string>

class Click;
class ColectorDeAcciones;
class Elemento {
 public:
  Elemento(std::string id,
             Punto pos,
             Vista *textura,
             bool esMio);
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
  virtual ~Elemento();

 protected:
  Vista* textura;
  std::string id;
  int currentClip;
  bool muerto;
  bool Mio;
  Rect rect;
};

#endif //TPFINAL_ELEMENTO_H
