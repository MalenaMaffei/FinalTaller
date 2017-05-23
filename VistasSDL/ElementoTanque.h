#ifndef TPFINAL_ELEMENTOTANQUE_H
#define TPFINAL_ELEMENTOTANQUE_H

#include "ElementoUnidad.h"
#include "VistaMuerteTanque.h"
class ElementoTanque : public ElementoUnidad {
 public:
  ElementoTanque(int id,
                 int x,
                 int y,
                 VistaDireccionada *textura,
                 Vista *texturaMuerte);

  void matar();
  void mostrar(Camara &camera);

 private:
  void morir();
  Vista* vistaMuerte;
  Vista* vistaMovimiento;

};

#endif //TPFINAL_ELEMENTOTANQUE_H
