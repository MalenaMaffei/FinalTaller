#ifndef TPFINAL_FABRICAUNIDAD_H
#define TPFINAL_FABRICAUNIDAD_H

#include "Vista.h"
#include "VistaDireccionada.h"
#include "ElementoUnidad.h"
#include "common_CodigosPaquete.h"
#include "../VistaManager.h"
#include "Mouse.h"
#include "Paquete.h"
#include <map>
class PaqueteEntrada;

class ElementoManager {
 public:
  ElementoManager(VistaManager &vistaManager,
                    int MiColor);

  void crear(Paquete &paquete);
  void mover(Paquete &paquete);
  void matar(Paquete &paquete);
  void disparar(Paquete &paquete);
  void elementosVivir(Camara &camara,
                      Click &click,
                      SelectBox &selectBox);
 private:
  void fabricarUnidad(Paquete &paquete);
  void fabricarElemento(Paquete &paquete);
  void limpiarMuertos(std::vector<int> &muertos);
  int miColor;
  std::map<int, Elemento *> elementos;
  std::map<int, ElementoUnidad *> unidades;
  CodigosPaquete codigos;
  VistaManager& vistaManager;
};

#endif //TPFINAL_FABRICAUNIDAD_H
