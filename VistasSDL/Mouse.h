#ifndef TPFINAL_MOUSE_H
#define TPFINAL_MOUSE_H
#include <SDL2/SDL.h>
#include "SelectBox.h"
class Mouse {

 public:
  bool leftButtonDown = false;
  bool mouseMoves = false;

  struct MouseCoords {
    int x = -1;
    int y = -1;
  };

  MouseCoords start_coords;
  MouseCoords move_coords;
  Mouse(){}

  void setState(Uint32 eventType, SDL_Event event);

  MouseCoords getCoordinates();

  SelectBox createSelectBox();
};

#endif //TPFINAL_MOUSE_H
