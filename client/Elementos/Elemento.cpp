#include "../Header Files/Elemento.h"
#include "../Header Files/Click.h"
#include "../Header Files/ColectorDeAcciones.h"
#include <string>
using std::string;

Elemento::Elemento(string id,Punto pos,Vista *textura,bool esMio)
    : textura(textura),id(id), currentClip(0), muerto(false), Mio(esMio) {
    rect.setPunto(pos);
    rect.w = textura->getWidth();
    rect.h = textura->getHeight();
}

void Elemento::mostrar(Camara &camera) {
    if (!muerto){
        if (camera.estaEnfocado(rect)){
            textura->mostrar(rect.getPunto() - camera.getPos(), currentClip);
        }
    }
}

bool Elemento::estaMuerto() const {
    return muerto;
}

void Elemento::matar() {
    muerto = true;
}

const Rect & Elemento::getRect() const {
    return rect;
}

string Elemento::getId() const {
    return id;
}

void Elemento::clicked(Click &click) {
    if (rect.incluyePunto(click.getPoint())){
        click.setClicked(this);
    }
}

bool Elemento::esMio() const {
    return Mio;
}

void Elemento::guiRequest(ColectorDeAcciones &colector) const {}
