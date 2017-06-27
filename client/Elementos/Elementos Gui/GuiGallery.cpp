#include "../../Header Files/GuiGallery.h"

GuiGallery::GuiGallery(Vista *vista,
                         Punto relPos) : vista(vista), relPos(relPos),
                                         seMuestra(false) {}

void GuiGallery::mostrar(Punto p) {
    if (seMuestra){
        vista->mostrar(relPos + p, clip);
    }
}

GuiGallery::~GuiGallery() {
    delete vista;
}

void GuiGallery::setInfo(PaqueteUnidad paquete) {}
void GuiGallery::setInfo(int tipo) {}
