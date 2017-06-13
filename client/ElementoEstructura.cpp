#include "Header Files/ElementoEstructura.h"
#include "Header Files/ColectorDeAcciones.h"
#include <string>
#define LARGO_ANIMACION 2
#define CLIP_MUERTE 2
ElementoEstructura::ElementoEstructura(std::string id,
                                       int x,
                                       int y,
                                       Vista *textura,
                                       bool esMio,
                                       int color) :
        ElementoColoreado(id,x,y,textura,esMio, color), destruido(false) {}

void ElementoEstructura::guiRequest(ColectorDeAcciones &colector) const {
    if (!destruido){
        colector.showEdificio(id);
    }
}

void ElementoEstructura::mostrar(Camara &camera) {
    if (!destruido){
        currentClip = textura->getClip(++currentClip);
        currentClip %= LARGO_ANIMACION;
    }
    ElementoColoreado::mostrar(camera);
}

void ElementoEstructura::matar() {
    currentClip = CLIP_MUERTE;
    destruido = true;
}

void ElementoEstructura::clicked(Click &click) {
    if (! destruido){
        Elemento::clicked(click);
    }
}
