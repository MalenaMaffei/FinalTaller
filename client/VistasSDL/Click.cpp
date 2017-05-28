#include "Click.h"
Click::Click() : clicked(nullptr){
    coords = {-1,-1};
}

void Click::setCoords(int clickedX,int clickedY) {
    coords = {clickedX, clickedY};
}

const SDL_Point &Click::getPoint() const {
    return coords;
}

void Click::setClicked(Elemento *clicked) {
    Click::clicked = clicked;
//    printf("me clickearon: %i y  habia seleccion?: %i\n", clicked->getId(), seleccion);
//      TODO esto lo tendria que manejar alguien de afuera, el colector de
// acciones. Lo de abajo funciona igual.
//    if (seleccion && !clicked->esMio()){
//        printf("atacar a %i!\n", clicked->getId());
//    } else {
//        printf("pedir informacion de: %i\n", clicked->getId());
//    }
}

void Click::setSeleccion(bool seleccion) {
    Click::seleccion = seleccion;
}

Elemento *Click::getClicked() const {
    return clicked;
}

bool Click::hayClickeado() {
    return clicked != nullptr;
}

void Click::resetCoords() {
    coords = {-1,-1};
}
bool Click::huboClick() {
    return coords.x >= 0;
}

//TODO delete coords after using them
