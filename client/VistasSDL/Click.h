#ifndef TPFINAL_CLICK_H
#define TPFINAL_CLICK_H

#include "Elemento.h"
class Click {
 public:
  Click();
  void setCoords(int clickedX,int clickedY);
  const SDL_Point &getPoint() const;
  void setClicked(Elemento *clicked);

 private:
  Elemento* clicked;
  SDL_Point point;
//  int x;
//  int y;
};

#endif //TPFINAL_CLICK_H
