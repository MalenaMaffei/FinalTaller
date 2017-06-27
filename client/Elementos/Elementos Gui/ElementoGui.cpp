#include "ElementoGui.h"

ElementoGui::ElementoGui(Vista *vista,
                         Punto relPos) : vista(vista), relPos(relPos),
                                         seMuestra(false) {}

void ElementoGui::mostrar(Punto p) {
    if (seMuestra){
        vista->mostrar(relPos + p, clip);
    }
}

ElementoGui::~ElementoGui() {
    delete vista;
}
