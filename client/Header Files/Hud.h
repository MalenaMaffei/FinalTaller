#ifndef TPFINAL_HUD_H
#define TPFINAL_HUD_H
#include "Vista.h"
#include "ProgressBar.h"
#include "PaqueteAccion.h"
#include "../ElementoGui.h"
#include "VistaHud.h"
#include <vector>
class Hud {
 public:
  Hud(SDL_Renderer *gRenderer, int color);
  virtual ~Hud();
  void mostrar();

//  Se setea la informacion que va  a necesitar el Hud para mostrarse
  void setInfo(Paquete paquete);
  bool click(Punto click);
  void abrirGui(std::string id, int color);
  bool activo();
  const std::string &getIdSeleccionado() const;
 private:
  VistaHud vistaHud;
  ProgressBar barraVida;
  bool seleccionado;
  Punto ubicacion;
  int color;
  Rect hudRect;
  bool esperandoInfo;
  std::string idSeleccionado;


//  NUEVOS ELEMENTOS
//TODO generar destructor.....
  std::vector<ElementoGui*> elementos;
};

#endif //TPFINAL_HUD_H
