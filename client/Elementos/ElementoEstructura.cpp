#include "../Header Files/ElementoEstructura.h"
#include "../Header Files/ColectorDeAcciones.h"
#include <string>
#define LARGO_ANIMACION 2
#define CLIP_MUERTE 2
ElementoEstructura::ElementoEstructura(std::string id,
                                       Punto pos,
                                       Vista *textura,
                                       bool esMio,
                                       int color) :
    ElementoColoreado(id, pos, textura, esMio, color), destruido(false) {}

void ElementoEstructura::guiRequest(ColectorDeAcciones &colector) const {
    if (!destruido && esMio()){
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
