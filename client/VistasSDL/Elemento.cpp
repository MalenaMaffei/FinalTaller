#include "Header Files/Elemento.h"
//TODO chequwar que todos tengan implementado el Mio
#include "Header Files/Click.h"
#include "Header Files/ColectorDeAcciones.h"
Elemento::Elemento(int id, int x, int y, Vista *textura, bool esMio)
    : textura(textura), id(id), currentClip(0), muerto(false), Mio(esMio) {
    rect.x = x;
    rect.y = y;

    //Set the collision box
    rect.w = textura->getWidth();
    rect.h = textura->getHeight();
}

void Elemento::mostrar(Camara &camera) {
    if(!muerto){
        if( camera.checkCollision( rect ) ){
            textura->mostrar(rect.getPunto() - camera.getOffset(), currentClip);
        }
    }

}

bool Elemento::estaMuerto() const {
    return muerto;
}

void Elemento::matar() {
    return;
}

const Rect & Elemento::getRect() const {
    return rect;
}

int Elemento::getId() const {
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

