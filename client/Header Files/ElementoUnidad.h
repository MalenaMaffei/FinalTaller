#ifndef TPFINAL_ELEMENTOMOVIL_H
#define TPFINAL_ELEMENTOMOVIL_H
#include <string>
#include "Elemento.h"
#include "VistaDireccionada.h"
#include "ElementoColoreado.h"

class SelectBox;
class ElementoUnidad : public ElementoColoreado{
 public:
  ElementoUnidad(std::string id,
                 int x,
                 int y,
                 VistaDireccionada *movimiento,
                 VistaDireccionada *disparar,
                 Vista *vistaMuerte,
                 bool esMio,
                 int color);

  void mover(Punto nuevo);

//  Override de Elemento. Dependiendo si el elemento esta muriendo,
// disparando o caminando, se muestran distintas imagenes.
  void mostrar(Camara &camera);

//  Chequear si el elemento esta dentro del rectangulo de seleccion
  void chequearSeleccion(SelectBox &selectBox);

  void matar();
  void disparar(Punto target);

//  En este caso (unidad) pide que se muestre el HUD
  void guiRequest(ColectorDeAcciones& colector) const;

 protected:
  void avanzarMuerte();
  void avanzarDisparo();
  int direccion;
  int estado;

  enum estados {
    enMovimiento = 0,
    disparando = 1,
    muriendo = 2,
    haciendoNada = 3
  };
//  TODO esto ya nbo se usa mas, comprobar y borrar
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
