#ifndef TPFINAL_ELEMENTOROBOT_H
#define TPFINAL_ELEMENTOROBOT_H

#include "Elemento.h"

class ElementoRobot : public Elemento{
 public:
  ElementoRobot(int id,
                  int x,
                  int y,
                  Vista *textura);

};

#endif //TPFINAL_ELEMENTOROBOT_H
