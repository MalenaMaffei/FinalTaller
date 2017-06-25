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
                   Punto pos,
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
  bool estaMuriendo();
//  En este caso (unidad) pide que se muestre el HUD
  void guiRequest(ColectorDeAcciones& colector) const;

 protected:
  void avanzarMuerte();
  void avanzarDisparo();
  VistaDireccionada* vistaMovimiento;
  VistaDireccionada* vistaDisparar;
  int direccion;
  int estado;
  Vista* vistaMuerte;
  enum estados {
    enMovimiento = 0,
    disparando = 1,
    muriendo = 2,
    haciendoNada = 3
  };
};

#endif //TPFINAL_ELEMENTOMOVIL_H
