#ifndef TPFINAL_CANVAS_H
#define TPFINAL_CANVAS_H
#include <SDL_render.h>
#include "ColaPaquetesVieja.h"
#include "ElementoManager.h"
#include "Hud.h"
#include "GuiEdificio.h"
#include "ColaPaquetes.h"

class Canvas{
 public:
  Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida);
  void close();
  void startGame();
  void manejarPaquetes(ElementoManager &elementoManager,
                         Hud &hud,
                         GuiEdificio &guiEdificio);

 private:
  //The window we'll be rendering to
  SDL_Window* gWindow;

//The window renderer
  SDL_Renderer* gRenderer;

  ColaPaquetes& colaEntrada;
  ColaPaquetes& colaSalida;
  Camara camara;
  int miColor;
  bool quit;
};

#endif //TPFINAL_CANVAS_H
