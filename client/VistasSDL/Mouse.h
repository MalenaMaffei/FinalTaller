#ifndef TPFINAL_MOUSE_H
#define TPFINAL_MOUSE_H
#include <SDL2/SDL.h>
#include "SelectBox.h"
#include "Click.h"
class Mouse {

 public:
//  struct MouseCoords {
//    int x = -1;
//    int y = -1;
//  };

  enum ButtonPressed{
    rightButtonDown = 0,
    rightButtonUp = 1,
    leftButtonDown = 2,
    leftButtonUp = 3
  };

  Mouse();

  void setState(Uint32 eventType, SDL_Event event, SDL_Point offset);

  SDL_Point getCoordinates();

  void setMouseAction(SelectBox &selectBox, Click &click);

 private:

//  bool rightButtonDown = false;
//  bool leftButtonDown = false;
  bool mouseMoves = false;
  SDL_Point start_coords;
  SDL_Point move_coords;
  SDL_Point left_click_coords;
  int lastButton;
};

#endif //TPFINAL_MOUSE_H
