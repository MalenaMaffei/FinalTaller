#include "Header Files/Click.h"
Click::Click() : clicked(nullptr){
    coords = {-1,-1};
}

void Click::setCoords(int clickedX,int clickedY) {
//    printf("me estan seteando las coords\n");
    coords = {clickedX, clickedY};
}

const Punto & Click::getPoint() const {
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
//    printf("reseting coords\n");
    coords = {-1,-1};
}
bool Click::huboClick() {
//    printf("mis coords son %i,%i\n", coords.x, coords.y);
    return coords.x >= 0;
}

//TODO delete coords after using them
