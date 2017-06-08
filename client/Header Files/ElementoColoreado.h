#ifndef TPFINAL_ELEMENTOCOLOREADO_H
#define TPFINAL_ELEMENTOCOLOREADO_H


#include "Elemento.h"

class ElementoColoreado : public Elemento{
public:
    ElementoColoreado(std::string id, int x, int y, Vista *textura, bool esMio,
                      int color);
    virtual void mostrar(Camara &camera);
protected:
    int color;
};


#endif //TPFINAL_ELEMENTOCOLOREADO_H
