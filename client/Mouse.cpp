#include "Header Files/Mouse.h"
#include "Header Files/Click.h"
#include <algorithm>
#include <cmath>

Mouse::Mouse() : lastButton(-1) {}

void Mouse::setState(Uint32 eventType, SDL_Event event, Punto offset) {
    if (eventType == SDL_MOUSEBUTTONDOWN) {
        Punto eventPunto(event.button.x, event.button.y);
        Mouse::screen_coords = eventPunto;
        if (event.button.button == SDL_BUTTON_RIGHT){
            lastButton = rightButtonDown;
            start_coords = eventPunto + offset;
        } else {
            lastButton = leftButtonDown;
            left_click_coords = eventPunto + offset;
        }
    }

    if (eventType == SDL_MOUSEBUTTONUP) {
        if (event.button.button ==  SDL_BUTTON_RIGHT) {
            lastButton = rightButtonUp;
        } else {
            lastButton = leftButtonUp;
        }
    }

    if (eventType == SDL_MOUSEMOTION) {
        move_coords = Punto(event.motion.x, event.motion.y) + offset;
    }
}

void Mouse::setMouseAction(SelectBox &selectBox, Click &click) {
    switch (lastButton){
        case rightButtonDown:{
//            Se setea el origen del Rectangulo de seleccion de selectBox y
// sus dimensiones si el mouse se movio
            int width = move_coords.x - start_coords.x;
            int height = start_coords.y - move_coords.y;
            int x = start_coords.x;
            int y = move_coords.y;

            int newX = std::min(x, x+width);
            int newY = std::min(y, y+height);

            Rect rect(Punto(newX,newY),std::abs(width),std::abs(height));
            selectBox.setRect(rect);
            selectBox.vaciarSeleccionadas();
        } break;

        case rightButtonUp:{
//            desaparece el rectangulo de seleccion cuando se deja de clickear
            selectBox.setRect(Rect());
        } break;

        case leftButtonUp:{
//            se le dice a Click donde se hizo click
            click.setPunto(left_click_coords);
            click.setScreenCoords(screen_coords);
            click.setSeleccion(selectBox.haySeleccion());
            click.setClicked(nullptr);
        } break;
    }
}

void Mouse::resetState() {
    if (lastButton != rightButtonDown){
        lastButton = none;
    }
}
