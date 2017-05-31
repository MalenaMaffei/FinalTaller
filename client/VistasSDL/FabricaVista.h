#ifndef TPFINAL_FABRICAVISTA_H
#define TPFINAL_FABRICAVISTA_H
#include <map>
#include "Header Files/Vista.h"
#include "Header Files/VistaDireccionada.h"
#include "Header Files/common_CodigosPaquete.h"

class FabricaVista {
 public:
  FabricaVista(std::map<int, Vista *> &vistas,
               std::map<int,
                        std::vector<VistaDireccionada *>> &vistasDireccionadas);

 private:
  std::map<int, Vista *> &vistas;
  std::map<int, std::vector<VistaDireccionada *>> &vistasDireccionadas;
  CodigosPaquete codigos;
};

#endif //TPFINAL_FABRICAVISTA_H
