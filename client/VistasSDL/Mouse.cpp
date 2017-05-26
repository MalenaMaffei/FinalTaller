#include "Mouse.h"
#include <algorithm>
#include <cmath>

Mouse::Mouse() : lastButton(-1) {}

void Mouse::setState(Uint32 eventType, SDL_Event event) {

    if ( eventType == SDL_MOUSEBUTTONDOWN) {
//        handleMouseDown(event);
        if (event.button.button == SDL_BUTTON_RIGHT){
            lastButton = rightButtonDown;
            start_coords.x = event.button.x;
            start_coords.y = event.button.y;
        } else {
////            TODO seleccion fabrica o seleccion terreno
        }

    }

    if ( eventType == SDL_MOUSEBUTTONUP ) {
        if (event.button.button ==  SDL_BUTTON_RIGHT) {
            lastButton = rightButtonUp;
        } else {
////            TODO manejar seleccion de fabricas etc
        }
    }

    if ( eventType == SDL_MOUSEMOTION ) {
        move_coords.x = event.motion.x;
        move_coords.y = event.motion.y;
    }
}

Mouse::MouseCoords Mouse::getCoordinates() {
    return move_coords;
}

void Mouse::setSelectBox(SelectBox &selectBox) {

    if(lastButton == rightButtonDown) {

        int width = move_coords.x - start_coords.x;
        int height = start_coords.y - move_coords.y;
        int x = start_coords.x ;
        int y = move_coords.y;

        int newX = std::min(x, x+width);
        int newY = std::min(y, y+height);

        SDL_Rect rect = {newX,newY,std::abs(width),std::abs(height)};
        selectBox.setRect(rect);
        selectBox.vaciarSeleccionadas();

    } else if (lastButton == rightButtonUp) {
        SDL_Rect rect = {0,0,0,0};
        selectBox.setRect(rect);
    }

}

