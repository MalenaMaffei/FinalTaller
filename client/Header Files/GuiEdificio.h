#ifndef TPFINAL_GUIEDIFICIO_H
#define TPFINAL_GUIEDIFICIO_H

#include "Vista.h"
#include <vector>
//TODO van a faltar las vistas de los bichos
//TODO es la misma para todos, el server me dice que puede construir, dsp
// vemos que hacer con el nombre
class GuiEdificio {
 public:
  GuiEdificio(Vista &vistaGui);
  void mostrar(Punto offset);
  void abrirGui(Punto pos, std::string id);
  bool click(Punto click);
  int getTipoSeleccionado() const;
  bool huboSeleccion() const;
  std::string getFabricaId() const;
 private:
  void resetSeleccion();
  Vista& vistaGui;
  Rect ok;
  Rect cancel;
  Rect next;
  bool seMuestra;
  Punto position;
  int posSeleccionada;
  int tipoSeleccionado;
  std::vector<int> tiposConstruibles;
  std::string fabricaId;
};

#endif //TPFINAL_GUIEDIFICIO_H
