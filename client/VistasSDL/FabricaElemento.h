#ifndef TPFINAL_FABRICAUNIDAD_H
#define TPFINAL_FABRICAUNIDAD_H

#include "Vista.h"
#include "VistaDireccionada.h"
#include "ElementoUnidad.h"
#include "common_Paquete.h"
#include <map>
class FabricaElemento {
 public:
  FabricaElemento(std::map<int, Vista *> &vistas,
                std::map<int,
                         std::vector<VistaDireccionada *>> vistasDireccionadas,
                std::map<int, Elemento *> &elementos,
                std::map<int, ElementoUnidad *> &unidades);

  void fabricar(Paquete &paquete);
 private:
  void fabricarUnidad(Paquete &paquete);
  void fabricarElemento(Paquete &paquete);

  std::map<int, Vista *> &vistas;
  std::map<int, std::vector<VistaDireccionada *>> &vistasDireccionadas;
  std::map<int, Elemento *> &elementos;
  std::map<int, ElementoUnidad *> &unidades;
  enum tipoElemento{
    roca = 0,
    puente = 1,
    bandera = 2,
    fuerte = 3,
    fabricaRobot = 4,
    fabricaVehiculo = 5,
  };
};

#endif //TPFINAL_FABRICAUNIDAD_H
