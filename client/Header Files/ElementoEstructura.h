#ifndef TPFINAL_ELEMENTOESTRUCTURA_H
#define TPFINAL_ELEMENTOESTRUCTURA_H

#include "Elemento.h"
#include "ElementoColoreado.h"
#include <string>
class ElementoEstructura : public ElementoColoreado{
 public:
  ElementoEstructura(std::string id,
                       Punto pos,
                       Vista *textura,
                       bool esMio,
                       int color);

  //  En este caso (Estructura) pide que se muestre el gui para crear unidades
  void guiRequest(ColectorDeAcciones& colector) const;

//  Override de mostrar Elemento, en este caso se deben mostar las animaciones
  void mostrar(Camara &camera);

//  Override de matar de Elemento, en este caso, no desaparece ni muere la
// estructura, sino que se destruye y cambia la imagen.
  void matar();

//  Override del clicked de Elemento, en este caso se chequea que no este
// destruida la estructura.
  void clicked(Click& click);

 private:
  bool destruido;
};

#endif //TPFINAL_ELEMENTOESTRUCTURA_H
