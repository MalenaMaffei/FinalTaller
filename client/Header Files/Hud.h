#ifndef TPFINAL_HUD_H
#define TPFINAL_HUD_H
#include "Vista.h"
#include "ProgressBar.h"
#include "PaqueteAccion.h"
#include "GuiGallery.h"
#include "VistaHud.h"
#include "Click.h"
#include <vector>
#include <string>
class Hud {
 public:
  explicit Hud(SDL_Renderer *gRenderer);
  virtual ~Hud();
  void mostrar();

//  Se setea la informacion que va  a necesitar el Hud para mostrarse
  void setInfo(PaqueteUnidad paquete);
  bool click(Click click);
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

//ElementosGui que componen al hud
  std::vector<GuiGallery*> elementos;
};

#endif //TPFINAL_HUD_H
