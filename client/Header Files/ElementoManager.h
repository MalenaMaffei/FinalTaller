#ifndef TPFINAL_FABRICAUNIDAD_H
#define TPFINAL_FABRICAUNIDAD_H

#include "Vista.h"
#include "VistaDireccionada.h"
#include "ElementoUnidad.h"
#include "common_CodigosPaquete.h"
#include "VistaManager.h"
#include "Mouse.h"
#include "PaqueteAccion.h"
#include "ElementoBala.h"
#include <map>
#include <string>
#include <vector>
class ElementoManager {
 public:
  ElementoManager(VistaManager &vistaManager,
                  int MiColor);
  virtual ~ElementoManager();

//  Aplican los distintos tipos de paquetes que conciernen a un elemento
  void crear(PaqueteAccion &paquete);
  void mover(PaqueteAccion &paquete);
  void matar(PaqueteAccion &paquete);
  void disparar(PaqueteAccion &paquete);

  bool unidadEsMia(const std::string &id) const;
//  Recorre todos los elementos chequeando si fueron clickeados,
// seleccionados o muertos.
  void elementosVivir(Camara &camara, Click &click, SelectBox &selectBox);

 private:
  void fabricarUnidad(PaqueteAccion &paquete);
  void fabricarElemento(PaqueteAccion &paquete);
  void limpiarMuertos(std::vector<std::string> &muertos);
  VistaManager& vistaManager;
  int miColor;
  std::map<std::string, Elemento *> elementos;
  std::map<std::string, ElementoUnidad *> unidades;
  std::map<std::string, ElementoBala*> balas;
  CodigosPaquete codigos;
};

#endif //TPFINAL_FABRICAUNIDAD_H
