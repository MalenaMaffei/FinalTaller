#ifndef TPFINAL_ELEMENTOMOVIL_H
#define TPFINAL_ELEMENTOMOVIL_H

#include "Elemento.h"
#include "VistaDireccionada.h"
//#include "SelectBox.h"

class SelectBox;
class ElementoUnidad : public Elemento{
 public:
  ElementoUnidad(int id,
                   int x,
                   int y,
                   VistaDireccionada *textura,
                   Vista *vistaMuerte,
                   bool esMio);
  virtual void mover(int newX, int newY);
  void mostrar(Camara &camera);
  void chequearSeleccion(SelectBox &selectBox, SDL_Point offset);
  void matar();
  void seleccionar();
  void deseleccionar();
 protected:
  void morir();

  //  TODO seguramente tenga que usar un enum aca pero estoy probando rapido el
// concepto
  int direccion;
  bool enMovimiento;
  bool disparando;
  bool muriendo;
  VistaDireccionada* vistaMovimiento;
  Vista* vistaMuerte;

};

#endif //TPFINAL_ELEMENTOMOVIL_H
