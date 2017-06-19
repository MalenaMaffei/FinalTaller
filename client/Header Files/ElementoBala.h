#ifndef TPFINAL_ELEMENTOBALA_H
#define TPFINAL_ELEMENTOBALA_H
#include <string> 
#include "Elemento.h"
class ElementoBala : public Elemento{
 public:
    ElementoBala(std::string id, int x, int y, Vista *textura);
    void mover(Punto nuevo);
    void matar();
    void clicked(Click& click);
};

#endif //TPFINAL_ELEMENTOBALA_H
