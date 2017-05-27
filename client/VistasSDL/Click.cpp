#include "Click.h"
Click::Click() : clicked(nullptr){
    point = {-1,-1};
}

void Click::setCoords(int clickedX,int clickedY) {
    point = {clickedX, clickedY};
}

const SDL_Point &Click::getPoint() const {
    return point;
}

void Click::setClicked(Elemento *clicked) {
    Click::clicked = clicked;
    printf("me clickearon: %i y  habia seleccion?: %i\n", clicked->getId(), seleccion);
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

//TODO delete coords after using them
