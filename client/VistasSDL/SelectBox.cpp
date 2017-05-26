#include "SelectBox.h"
#include <algorithm>

void SelectBox::mostrar(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer , 0 , 255 , 0 , 255);
    SDL_RenderDrawRect(renderer, &rect);
    std::for_each(seleccionadas.begin(), seleccionadas.end(), [&]
        (ElementoUnidad &unidad){
        SDL_Rect rectUnidad = unidad.getRect();
        SDL_RenderDrawRect(renderer, &rectUnidad);
    });
}

SelectBox::SelectBox() {
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;

}

void SelectBox::setRect(const SDL_Rect &rect) {
    SelectBox::rect = rect;
}

bool SelectBox::checkCollision(SDL_Rect b) {
    SDL_bool res = SDL_HasIntersection(&rect, &b);
    if (res == SDL_TRUE){
        return true;
    }
    return false;
}

int SelectBox::getX() {
    return rect.x;
}

int SelectBox::getY() {
    return rect.y;
}

void SelectBox::selectUnidad(ElementoUnidad &unidad) {
//    unidad.seleccionar();
    seleccionadas.push_back(unidad);
    printf("cantidad seleccionados:%i \n", seleccionadas.size());
}

void SelectBox::vaciarSeleccionadas() {
    std::for_each(seleccionadas.begin(), seleccionadas.end(), []
        (ElementoUnidad &unidad){
//      unidad.deseleccionar();
    });
    seleccionadas.clear();
}

bool SelectBox::haySeleccion() {
    return seleccionadas.empty();
}
