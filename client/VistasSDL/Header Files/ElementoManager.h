#ifndef TPFINAL_FABRICAUNIDAD_H
#define TPFINAL_FABRICAUNIDAD_H

#include "Vista.h"
#include "VistaDireccionada.h"
#include "ElementoUnidad.h"
#include "common_CodigosPaquete.h"
#include "../VistaManager.h"
#include "Mouse.h"
#include "common_PaqueteEntrada.h"
#include <map>
class PaqueteEntrada;

class ElementoManager {
 public:
  ElementoManager(VistaManager &vistaManager);

  void fabricar(PaqueteEntrada &paquete);
  void mover(PaqueteEntrada &paquete);
  void matar(PaqueteEntrada &paquete);
  void disparar(PaqueteEntrada &paquete);
  void elementosVivir(Camara &camara,
                      Click &click,
                      SelectBox &selectBox);
 private:
  void fabricarUnidad(PaqueteEntrada &paquete);
  void fabricarElemento(PaqueteEntrada &paquete);
  void limpiarMuertos(std::vector<int> &muertos);

  std::map<int, Elemento *> elementos;
  std::map<int, ElementoUnidad *> unidades;
  CodigosPaquete codigos;
  VistaManager& vistaManager;
};

#endif //TPFINAL_FABRICAUNIDAD_H
