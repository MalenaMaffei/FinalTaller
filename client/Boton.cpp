#include "Boton.h"

Boton::Boton(Punto posRel, int w, int h) {
    botonRelativo = Rect(posRel, w, h);
}

void Boton::ubicar(Punto p) {
    botonAbsoluto = botonRelativo.positiveShift(p);
}

bool Boton::wasPressed(Punto click) {
    return botonAbsoluto.incluyePunto(click);
}

