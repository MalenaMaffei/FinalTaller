#ifndef TPFINAL_ELEMENTOMOVIL_H
#define TPFINAL_ELEMENTOMOVIL_H

#include "Elemento.h"
#include "VistaDireccionada.h"
#include "ElementoColoreado.h"
//#include "SelectBox.h"

class SelectBox;
class ElementoUnidad : public ElementoColoreado{
 public:
  ElementoUnidad(int id,
                   int x,
                   int y,
                   VistaDireccionada *movimiento,
                   VistaDireccionada *disparar,
                   Vista *vistaMuerte,
                   bool esMio,
                   int color);
  virtual void mover(Punto nuevo);
  void mostrar(Camara &camera);
  void chequearSeleccion(SelectBox &selectBox);
  void matar();
  void disparar(Punto target);
  void seleccionar();
  void deseleccionar();
  void guiRequest(ColectorDeAcciones& colector) const;
 protected:
  void avanzarMuerte();
  void avanzarDisparo();
  //  TODO seguramente tenga que usar un enum aca pero estoy probando rapido el
// concepto
  int direccion;
//  bool enMovimiento;
//  bool disparando;
//  bool muriendo;
  int estado;
  enum {
    enMovimiento = 0,
    disparando = 1,
    muriendo = 2,
    haciendoNada = 3
  };
  enum {
    norte = 2,
    noroeste = 3,
    oeste = 4,
    suroeste = 5,
    sur = 6,
    sureste = 7,
    este = 0,
    noreste = 1,
    centro = 9
  };
  VistaDireccionada* vistaMovimiento;
  VistaDireccionada* vistaDisparar;
  Vista* vistaMuerte;

};

#endif //TPFINAL_ELEMENTOMOVIL_H
