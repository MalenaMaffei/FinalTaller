#include "Click.h"
Click::Click() : clicked(nullptr){}

void Click::setCoords(int clickedX,int clickedY) {
    point = {clickedX, clickedY};
}

const SDL_Point &Click::getPoint() const {
    return point;
}

void Click::setClicked(Elemento *clicked) {
    Click::clicked = clicked;
    printf("me clickearon: %i\n", clicked->getId());
}

//TODO delete coords after using them
