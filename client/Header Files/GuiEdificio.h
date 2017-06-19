#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H
#include "Vista.h"
#include "VistaTexto.h"
#include "VistaGui.h"
#include "PaqueteFabrica.h"
#include "ProgressBar.h"
#include <vector>
#include <map>
#include <string>

//TODO van a faltar las vistas de los bichos
//TODO es la misma para todos, el server me dice que puede construir, dsp
// vemos que hacer con el nombre
class GuiEdificio {
 public:
  explicit GuiEdificio(SDL_Renderer *gRenderer);

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

 private:
  void resetSeleccion();
  VistaGui vistaGui;
  VistaTexto vistaTexto;
  ProgressBar barraConstr;
  Rect ok;
  Rect cancel;
  Rect next;
  bool seMuestra;
  Punto posUNIT;
  Punto posVida;
  Punto posNombre;
  Punto position;
  Rect relPosOK;
  Rect relPosCANCEL;
  Rect relPosNEXT;

  std::string idFabrica;
  int posSeleccionada;
  int tipoSeleccionado;
  std::vector<int> tiposConstruibles;
  std::map<int, std::string> tiemposConstruibles;
  int tipoFabrica;
  std::string vida;
  float porcentajeConstruido;
  int tipoEnConstruccion;
  bool hayEnConstruccion;
};

#endif //TPFINAL_GUIEDIFICIO_H
