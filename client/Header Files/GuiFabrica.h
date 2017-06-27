#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H
#include "Vista.h"
#include "VistaTexto.h"
#include "VistaGui.h"
#include "PaqueteFabrica.h"
#include "ProgressBar.h"
#include "Boton.h"
#include "Paquete.h"
#include "FactoryGallery.h"
#include <vector>
#include <map>
#include <string>

class GuiFabrica {
 public:
  explicit GuiFabrica(SDL_Renderer *gRenderer,
                       VistaTexto &vistaTexto);

  void mostrar(Camara &camara);

//  Se setea que fabrica hizo el pedido de abrir gui y en donde se hizo el
// click para mostrar despues ahi al gui
  void abrirGui(Punto pos, std::string id);

//  Se chequea si algun boton fue clickeado
  bool click(Punto click);

  int getTipoSeleccionado() const;

//  Se selecciono alguna unidad para construir?
  bool huboSeleccion() const;

  std::string getIdFabrica() const;

//  Setea los distintos elementos a mostrar usando el paquete.
  void setInfo(PaqueteFabrica paquete);
  bool activo();
  virtual ~GuiFabrica();

 private:
  void resetSeleccion();
  VistaGui vistaGui;
  VistaTexto& vistaTexto;
  ProgressBar barraConstr;
  bool seMuestra;
  int tipoSeleccionado;
  int posSeleccionada;
  Boton ok;
  Boton cancel;
  Boton next;
  Punto posUNIT;
  Punto posVida;
  Punto posNombre;
  Punto position;

  std::string idFabrica;
  Paquete paquete;

  std::vector<int> tiposConstruibles;
  std::map<int, std::string> tiemposConstruibles;
  int tipoFabrica;
  std::string vida;
  float porcentajeConstruido;
  int tipoEnConstruccion;
  bool hayEnConstruccion;
  bool esperandoInfo;
  FactoryGallery gallery;
};

#endif //TPFINAL_GUIEDIFICIO_H
