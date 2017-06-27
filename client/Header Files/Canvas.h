#ifndef TPFINAL_CANVAS_H
#define TPFINAL_CANVAS_H
#include <SDL_render.h>
#include "ElementoManager.h"
#include "Hud.h"
#include "GuiFabrica.h"
#include "ColaPaquetes.h"
#include "Mapa.h"
#include "Reproductor.h"

class Canvas{
 public:
  Canvas(ColaPaquetes &colaEntrada, ColaPaquetes &colaSalida);
 public:
  void inicializarDatos(Mapa& mapa);
//  void close();
  void startGame();
  void manejarPaquetes(ElementoManager &elementoManager,
                         Hud &hud,
                         GuiFabrica &guiEdificio,
                         Reproductor &reproductor);
  void gameLoop(ElementoManager &elementoManager,
                  Hud &hud,
                  GuiFabrica &guiEdificio,
                  ColectorDeAcciones &colector,
                  Mapa &mapa);
  virtual ~Canvas();

 private:
  void mensajeEsperando();
  //The window we'll be rendering to
  SDL_Window* gWindow;

//The window renderer
  SDL_Renderer* gRenderer;

  ColaPaquetes& colaEntrada;
  ColaPaquetes& colaSalida;
  Camara camara;
  Mouse mouse;
  SelectBox selectBox;
  Click click;
  int miColor;
  bool quit;
};

#endif //TPFINAL_CANVAS_H
