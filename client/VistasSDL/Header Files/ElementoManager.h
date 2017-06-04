#ifndef TPFINAL_FABRICAUNIDAD_H
#define TPFINAL_FABRICAUNIDAD_H

#include "Vista.h"
#include "VistaDireccionada.h"
#include "ElementoUnidad.h"
#include "common_Paquete.h"
#include "common_CodigosPaquete.h"
#include "../VistaManager.h"
#include <map>
class ElementoManager {
 public:
  ElementoManager(VistaManager &vistaManager);

  void fabricar(Paquete &paquete);
 private:
  void fabricarUnidad(Paquete &paquete);
  void fabricarElemento(Paquete &paquete);

  std::map<int, Elemento *> elementos;
  std::map<int, ElementoUnidad *> unidades;
  CodigosPaquete codigos;
  VistaManager& vistaManager;
};

#endif //TPFINAL_FABRICAUNIDAD_H
