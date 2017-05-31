#ifndef TPFINAL_ELEMENTOCOLOREADO_H
#define TPFINAL_ELEMENTOCOLOREADO_H


#include "Elemento.h"

class ElementoColoreado : public Elemento{
public:
    ElementoColoreado(int id, int x, int y, Vista *textura, bool esMio,
                      int color);

protected:
    int color;
};


#endif //TPFINAL_ELEMENTOCOLOREADO_H
