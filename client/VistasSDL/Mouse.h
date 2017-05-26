#ifndef TPFINAL_MOUSE_H
#define TPFINAL_MOUSE_H
#include <SDL2/SDL.h>
#include "SelectBox.h"
class Mouse {

 public:
  struct MouseCoords {
    int x = -1;
    int y = -1;
  };

  enum ButtonPressed{
    rightButtonDown = 0,
    rightButtonUp = 1,
    leftButtonDown = 2,
    leftButtonUp = 3
  };

  Mouse();

  void setState(Uint32 eventType, SDL_Event event);

  MouseCoords getCoordinates();

  void setSelectBox(SelectBox &selectBox);

 private:

//  bool rightButtonDown = false;
//  bool leftButtonDown = false;
  bool mouseMoves = false;
  MouseCoords start_coords;
  MouseCoords move_coords;
  int lastButton;
};

#endif //TPFINAL_MOUSE_H
