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
