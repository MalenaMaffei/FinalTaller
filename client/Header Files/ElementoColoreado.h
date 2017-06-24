#ifndef TPFINAL_ELEMENTOCOLOREADO_H
#define TPFINAL_ELEMENTOCOLOREADO_H
#include "Elemento.h"
#include <string>

class ElementoColoreado : public Elemento{
public:
    ElementoColoreado(std::string id,
                          Punto pos,
                          Vista *textura,
                          bool esMio,
                          int color);
    virtual void mostrar(Camara &camera);
protected:
    int color;
};


#endif //TPFINAL_ELEMENTOCOLOREADO_H
