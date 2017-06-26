#include "Header Files/Click.h"
Click::Click() : clicked(nullptr){
    coords = {-1,-1};
}

void Click::setPunto(Punto punto) {
    coords = punto;
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

const Punto &Click::getScreenCoords() const {
    return screenCoords;
}

void Click::setScreenCoords(const Punto &screenCoords) {
    Click::screenCoords = screenCoords;
}

//TODO delete coords after using them
