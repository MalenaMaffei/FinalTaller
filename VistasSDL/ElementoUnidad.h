#ifndef TPFINAL_ELEMENTOMOVIL_H
#define TPFINAL_ELEMENTOMOVIL_H

#include "Elemento.h"
#include "VistaDireccionada.h"
class ElementoUnidad : public Elemento{
 public:
  ElementoUnidad(int id,
                   int x,
                   int y,
                   VistaDireccionada *textura,
                   Vista *vistaMuerte);
  virtual void mover(int newX, int newY);
  void mostrar(Camara &camera);
  void matar();
 protected:
  void morir();

  //  TODO seguramente tenga que usar un enum aca pero estoy probando rapido el
// concepto
  int direccion;
  bool enMovimiento;
  bool disparando;
  bool muriendo;
  VistaDireccionada* texturaDireccionada;
  Vista* vistaMuerte;

};

#endif //TPFINAL_ELEMENTOMOVIL_H
