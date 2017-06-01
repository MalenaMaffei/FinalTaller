#ifndef TPFINAL_ELEMENTO_H
#define TPFINAL_ELEMENTO_H

#include <SDL_rect.h>
#include "Vista.h"
//#include "Click.h"
class Click;
class ColectorDeAcciones;
class Elemento {
 public:
//  TODO refactorizar la necesidad de pasar width height
  Elemento(int id, int x, int y, Vista *textura, bool esMio);
  virtual void mostrar(Camara &camera);
  virtual bool estaMuerto() const;
//  TODO deberia ser virtual total pero por ahora lo dejo vacio porque no
// tengo tiempo de ponerme hacer todos de un saque antes de probar
  virtual void matar();
  const Rect & getRect() const;
  int getId() const;
  void clicked(Click& click);
  bool esMio() const;
  virtual void guiRequest(ColectorDeAcciones& colector) const;
 protected:
  //The attributes of the tile
  bool Mio;
  bool muerto;
  Rect rect;

  Vista* textura;
  int id;
  int currentClip;
};

#endif //TPFINAL_ELEMENTO_H
