#include "ElementoTanque.h"
#include "VistaMuerteTanque.h"
ElementoTanque::ElementoTanque(int id,
                               int x,
                               int y,
                               VistaDireccionada *textura,
                               Vista *texturaMuerte)
    : ElementoUnidad(id, x, y, textura, texturaMuerte), vistaMuerte(texturaMuerte),
      vistaMovimiento(textura) {}



void ElementoTanque::matar() {
    if (muriendo || estaMuerto() ){
        return;
    }
    currentClip = 0;
    muriendo = true;
    enMovimiento = false;
    disparando = false;
    textura = vistaMuerte;
//    Elemento::matar();
}



void ElementoTanque::mostrar(Camara &camera) {
    Elemento::mostrar(camera);
    if (muriendo){
        morir();
    }
}


void ElementoTanque::morir() {
    if (vistaMuerte->isLastClip(currentClip)){
        muriendo = false;
        muerto = true;
        return;
    }
    ++currentClip;
    currentClip = vistaMuerte->getClip(currentClip);

}
