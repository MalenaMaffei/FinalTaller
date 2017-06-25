#ifndef TPFINAL_HUD_H
#define TPFINAL_HUD_H
#include "Vista.h"
#include "ProgressBar.h"
#include "Paquete.h"
#include "../ElementoGui.h"
#include "VistaHud.h"
class Hud {
 public:
  Hud(SDL_Renderer *gRenderer, int color);
  void mostrar();

//  Se setea la informacion que va  a necesitar el Hud para mostrarse
  void setInfo(Paquete paquete);

 private:
  VistaHud vistaHud;
//  Vista vistaCaras;
//  Vista labelsRobot;
//  Vista labelsVehiculo;
  Rect hudRect;
  ProgressBar barraVida;
//  int x, y;
  Punto ubicacion;
  int tipoCara;
//  float vida;
  bool seleccionado;
  int aMostrar;
  int color;
  enum posibilidades{
    cara = 0,
    tanque = 1,
    caraYtanque = 2
  };

  enum posLabels {
    labelGrunt = 0,
    labelLaser = 1,
    labelPsychos = 2,
    labelPyros = 3,
    labelSniper = 4,
    labelTough = 5
  };


//  NUEVOS ELEMENTOS
//TODO generar destructor.....
  std::vector<ElementoGui*> elementos;
};

#endif //TPFINAL_HUD_H
