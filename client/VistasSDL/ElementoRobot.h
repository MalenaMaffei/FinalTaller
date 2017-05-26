#ifndef TPFINAL_ELEMENTOROBOT_H
#define TPFINAL_ELEMENTOROBOT_H

#include "Elemento.h"
#include "ElementoUnidad.h"

class ElementoRobot : public ElementoUnidad{
 public:
  ElementoRobot(int id,
                  int x,
                  int y,
                  VistaDireccionada *texturaCaminar,
                  VistaDireccionada *texturaDisparar,
                  Vista *vistaMuerte,
                  bool esMio);
 private:
  Vista* texturaDisparar;
//  Vista* currentVista;

};

#endif //TPFINAL_ELEMENTOROBOT_H
