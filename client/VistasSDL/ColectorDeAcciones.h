#ifndef TPFINAL_COLECTORDEACCIONES_H
#define TPFINAL_COLECTORDEACCIONES_H

#include "SelectBox.h"
#include "Click.h"
class ColectorDeAcciones {
 public:
  ColectorDeAcciones(SelectBox &selectBox, Click &click);

  void crearAcciones();

 private:
  SelectBox &selectBox;
  Click &click;
};

#endif //TPFINAL_COLECTORDEACCIONES_H
