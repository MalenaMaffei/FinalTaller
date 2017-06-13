#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H

#include "Vista.h"
#include "../VistaTexto.h"
#include "VistaGui.h"
#include "../PaqueteFabrica.h"
#include <vector>
#include <map>
//TODO van a faltar las vistas de los bichos
//TODO es la misma para todos, el server me dice que puede construir, dsp
// vemos que hacer con el nombre
class GuiEdificio {
 public:
  GuiEdificio(SDL_Renderer *gRenderer);
  void mostrar(Punto offset);
  void abrirGui(Punto pos, std::string id);
  bool click(Punto click);
  int getTipoSeleccionado() const;
  bool huboSeleccion() const;
  std::string getFabricaId() const;
  void setInfo(PaqueteFabrica paquete);
 private:
  void resetSeleccion();
  VistaGui vistaGui;
  VistaTexto vistaTexto;
  Rect ok;
  Rect cancel;
  Rect next;
  bool seMuestra;
  Punto position;
  Punto offsetOK;
  Punto offsetCANCEL;
  Punto offsetNEXT;
  Punto offsetUNIT;

  int posSeleccionada;
  int tipoSeleccionado;
  std::vector<int> tiposConstruibles;
  std::map<int, std::string> tiemposConstruibles;
  std::string fabricaId;
};

#endif //TPFINAL_GUIEDIFICIO_H
