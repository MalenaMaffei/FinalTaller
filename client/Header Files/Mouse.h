#ifndef TPFINAL_MOUSE_H
#define TPFINAL_MOUSE_H
#include <SDL2/SDL.h>
#include "SelectBox.h"
#include "Click.h"
class Mouse {
 public:
  enum ButtonPressed{
    none = -1,
    rightButtonDown = 0,
    rightButtonUp = 1,
    leftButtonDown = 2,
    leftButtonUp = 3
  };

  Mouse();

//  Setea el estado del mouse dependiendo al evento recibido
  void setState(Uint32 eventType, SDL_Event event, Punto offset);
  void resetState();
  Punto getCoordinates();

//  Dependiendo la secuencia de eventos registrados modifica a Click o a
// selectBox (buttonDOWN, drag, buttonUP seria seleccionar unidades por ejemplo)
  void setMouseAction(SelectBox &selectBox, Click &click);

 private:
  bool mouseMoves = false;
  Punto start_coords;
  Punto move_coords;
  Punto left_click_coords;
  Punto screen_coords;
  int lastButton;
};

#endif //TPFINAL_MOUSE_H
