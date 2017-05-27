#include "Mouse.h"
#include "Click.h"
#include <algorithm>
#include <cmath>

Mouse::Mouse() : lastButton(-1) {}

void Mouse::setState(Uint32 eventType, SDL_Event event, SDL_Point offset) {

    if ( eventType == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_RIGHT){
            lastButton = rightButtonDown;
//            start_coords = {event.button.x, event.button.y};
            start_coords = {event.button.x + offset.x, event.button.y +
                offset.y};
//            printf("Rclick en x: %i, y: %i\n", start_coords.x,
//                   start_coords.y);
        } else {
////            TODO seleccion fabrica o seleccion terreno
        }

    }

    if ( eventType == SDL_MOUSEBUTTONUP ) {
        if (event.button.button ==  SDL_BUTTON_RIGHT) {
            lastButton = rightButtonUp;
        } else {
            lastButton = leftButtonUp;
            left_click_coords = {event.button.x + offset.x, event.button.y +
                offset.y};
//            left_click_coords = {event.button.x, event.button.y };
//            printf("click en x: %i, y: %i\n", left_click_coords.x, left_click_coords.y);
        }
    }

    if ( eventType == SDL_MOUSEMOTION ) {
//        move_coords = {event.motion.x, event.motion.y};
        move_coords = {event.motion.x+ offset.x, event.motion.y+ offset.y};
    }
}

SDL_Point Mouse::getCoordinates() {
    return move_coords;
}

void Mouse::setMouseAction(SelectBox &selectBox, Click &click) {
    switch (lastButton){
        case rightButtonDown:{
            int width = move_coords.x - start_coords.x;
            int height = start_coords.y - move_coords.y;
            int x = start_coords.x ;
            int y = move_coords.y;

            int newX = std::min(x, x+width);
            int newY = std::min(y, y+height);

            SDL_Rect rect = {newX,newY,std::abs(width),std::abs(height)};
            selectBox.setRect(rect);
            selectBox.vaciarSeleccionadas();
            printf("pos rect creado: %i,%i\n", newX, newY);
        } break;

        case rightButtonUp:{
            SDL_Rect rect = {0,0,0,0};
            selectBox.setRect(rect);
        } break;

        case leftButtonUp:{
            click.setCoords(left_click_coords.x,left_click_coords.y);
            click.setSeleccion(selectBox.haySeleccion());
        }

    }

}

