#ifndef TPFINAL_CANVAS_H
#define TPFINAL_CANVAS_H
#include <SDL_render.h>
#include "common_Thread.h"
#include "ColaPaquetes.h"
#include "ElementoManager.h"
#include "Hud.h"
#include "GuiEdificio.h"

class Canvas : public Thread{
 public:
  Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida);
  void close();
  void run();
  void gameLoop();
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
};

#endif //TPFINAL_CANVAS_H
