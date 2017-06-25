#ifndef TPFINAL_ELEMENTOGUI_H
#define TPFINAL_ELEMENTOGUI_H

#include "Header Files/Punto.h"
#include "Header Files/Vista.h"
#include "Header Files/Paquete.h"
class ElementoGui {
 public:
  ElementoGui(Vista *vista,
              Punto relPos);
  void mostrar(Punto p);
  virtual void setInfo(Paquete paquete)=0;
  virtual ~ElementoGui();

 protected:
  Vista* vista;
  Punto relPos;
  bool seMuestra;
  int clip;
  CodigosPaquete codigos;
};

#endif //TPFINAL_ELEMENTOGUI_H
