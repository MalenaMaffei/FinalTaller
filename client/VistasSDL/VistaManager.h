#ifndef TPFINAL_FABRICAVISTA_H
#define TPFINAL_FABRICAVISTA_H
#include <map>
#include "Header Files/Vista.h"
#include "Header Files/VistaDireccionada.h"
#include "Header Files/common_CodigosPaquete.h"

class VistaManager {
 public:
  VistaManager();
  VistaDireccionada* getVistaDisparo(int tipoUnidad);
  VistaDireccionada* getVistaCaminar(int tipoUnidad);
//  Vista* getVistaMuerte(int tipoUnidad);
  Vista* getVista(int tipoElemento);

 private:
  std::map<int, Vista *> vistas;
  std::map<int, std::vector<VistaDireccionada *>> vistasDireccionadas;
  CodigosPaquete codigos;

  void fabricarVistasDeElemento(int tipo);
  VistaDireccionada* getVistaDireccionada(int tipoUnidad, int tipoVista);
};

#endif //TPFINAL_FABRICAVISTA_H
