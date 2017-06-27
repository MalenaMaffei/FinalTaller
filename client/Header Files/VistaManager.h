#ifndef TPFINAL_FABRICAVISTA_H
#define TPFINAL_FABRICAVISTA_H
#include <map>
#include <vector>
#include "Vista.h"
#include "VistaDireccionada.h"
#include "common_CodigosPaquete.h"

class VistaManager {
 public:
  explicit VistaManager(SDL_Renderer *gRenderer);
  VistaDireccionada* getVistaDisparo(int tipoUnidad);
  VistaDireccionada* getVistaCaminar(int tipoUnidad);
  Vista* getVista(int tipoElemento);
  virtual ~VistaManager();

 private:
  std::map<int, Vista *> vistas;
  std::map<int, std::vector<VistaDireccionada *>> vistasDireccionadas;
  CodigosPaquete codigos;
  SDL_Renderer *gRenderer;

  void fabricarVistasDeElemento(int tipo);
  VistaDireccionada* getVistaDireccionada(int tipoUnidad, int tipoVista);
};

#endif //TPFINAL_FABRICAVISTA_H
