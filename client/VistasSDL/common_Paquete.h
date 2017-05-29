#ifndef TPFINAL_PAQUETE_H
#define TPFINAL_PAQUETE_H
#include <string>
#include <map>
#include "Vista.h"
#include "VistaDireccionada.h"
#include "Elemento.h"
#include "ElementoUnidad.h"
class Paquete {
 public:
  Paquete(std::string mensaje);
  void aplicar(std::map<int, Vista> &vistas, std::map<int, VistaDireccionada>
  &vistasDireccionadas, std::map<int, Elemento> &elementos,
               std::map<int, ElementoUnidad> &unidades);
 private:
  enum comando{
    crear = 0,
    matar = 1,
    mover = 2,
    disparar = 3
  };
  int id;
  int comando;
  int x;
  int y;
  int tipo;
  bool esMio;
  int color;

};

#endif //TPFINAL_PAQUETE_H
