#ifndef TPFINAL_HUD_H
#define TPFINAL_HUD_H
#include "Vista.h"
#include "ProgressBar.h"
class Hud {
 public:
  Hud(SDL_Renderer *gRenderer,
        Vista &hud,
        Vista &vistaCaras,
        Vista &labelsRobot,
        Vista &labelsVehiculo,
        ProgressBar &barraVida);
  void mostrar();
  void setInfo(int tipo, int porcentajeVida);

 private:
  void mostrarContenido();
  int getPosLabel();
  Vista& vistaHud;
  Vista& vistaCaras;
  Vista labelsRobot;
  Vista labelsVehiculo;
  Rect hudRect;
  ProgressBar barraVida;
//  int x, y;
  Punto ubicacion;
  int tipoCara;
  float vida;
  bool seleccionado;
  int aMostrar;
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
};

#endif //TPFINAL_HUD_H
