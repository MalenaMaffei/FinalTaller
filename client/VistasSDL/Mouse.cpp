#include "Mouse.h"



void Mouse::setState(Uint32 eventType, SDL_Event event) {

    if ( eventType == SDL_MOUSEBUTTONDOWN) {
//        handleMouseDown(event);
        if (event.button.button == SDL_BUTTON_RIGHT){
            rightButtonDown = true;
            start_coords.x = event.button.x;
            start_coords.y = event.button.y;
        } else {
////            TODO seleccion fabrica o seleccion terreno
        }

    }

    if ( eventType == SDL_MOUSEBUTTONUP ) {
        if (event.button.button ==  SDL_BUTTON_RIGHT) {
            rightButtonDown = false;
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

    if(this->rightButtonDown) {

        int width = move_coords.x - start_coords.x;
        int height = start_coords.y - move_coords.y;
        int x = start_coords.x ;
        int y = move_coords.y;

        SDL_Rect rect = {x,y,width,height};
        selectBox.setRect(rect);
//        SelectBox rect(x, y,width, height);
//        return rect;
    } else {
        SDL_Rect rect = {0,0,0,0};
        selectBox.setRect(rect);
    }

}
