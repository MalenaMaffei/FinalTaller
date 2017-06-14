#ifndef TPFINAL_ELEMENTOESTRUCTURA_H
#define TPFINAL_ELEMENTOESTRUCTURA_H

#include "Elemento.h"
#include "ElementoColoreado.h"
#include <string>
class ElementoEstructura : public ElementoColoreado{
 public:
  ElementoEstructura(std::string id, int x, int y, Vista *textura,
                     bool esMio, int color);
  void guiRequest(ColectorDeAcciones& colector) const;
  void mostrar(Camara &camera);
  void matar();
  void clicked(Click& click);
 private:
  bool destruido;
};

#endif //TPFINAL_ELEMENTOESTRUCTURA_H
