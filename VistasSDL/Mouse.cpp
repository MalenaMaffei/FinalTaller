#include "Mouse.h"
void Mouse::setState(Uint32 eventType, SDL_Event event) {

    if ( eventType == SDL_MOUSEBUTTONDOWN) {
        this->leftButtonDown = true;
        this->start_coords.x = event.button.x;
        this->start_coords.y = event.button.y;
    }

    if ( eventType == SDL_MOUSEBUTTONUP ) {
        this->leftButtonDown = false;
    }

    if ( eventType == SDL_MOUSEMOTION ) {
        this->move_coords.x = event.motion.x;
        this->move_coords.y = event.motion.y;
    }
}

Mouse::MouseCoords Mouse::getCoordinates() {
    return move_coords;
}

SelectBox Mouse::createSelectBox() {

    if(this->leftButtonDown) {

        float width = this->move_coords.x - this->start_coords.x;
        float height = this->start_coords.y - this->move_coords.y;
        float x = this->start_coords.x ;
        float y = this->move_coords.y;

        SelectBox rect(x, y,width, height);
        return rect;
    }
}
