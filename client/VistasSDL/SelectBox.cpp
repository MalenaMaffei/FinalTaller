#include "Header Files/SelectBox.h"
#include <algorithm>

void SelectBox::mostrar(SDL_Renderer *renderer, Punto offset) {
//    TODO no dibujar cuando no hay colision, voy a tener que pasar la camara
    SDL_SetRenderDrawColor(renderer , 0 , 255 , 0 , 255);

//    SDL_Rect displayRect = {rect.x - offset.x, rect.y - offset.y, rect.w,
//                            rect.h};
    Rect displayRect(rect.getPunto() - offset, rect.w, rect.h);

    SDL_RenderDrawRect(renderer, &displayRect);
    std::for_each(seleccionadas.begin(), seleccionadas.end(), [&]
        (ElementoUnidad &unidad){
        Rect rectUnidad = unidad.getRect();
//        displayRect = {rectUnidad.x - offset.x, rectUnidad.y - offset.y, rectUnidad.w,
//                       rectUnidad.h};
        displayRect = Rect(rectUnidad.getPunto() - offset, rectUnidad.w,
                           rectUnidad.h);
        SDL_RenderDrawRect(renderer, &displayRect);
    });
}

SelectBox::SelectBox() {
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;

}

void SelectBox::setRect(const Rect &rect) {
    SelectBox::rect = rect;
}

bool SelectBox::checkCollision(Rect b) {
//    SDL_bool res = SDL_HasIntersection(&rect, &b);
//    if (res == SDL_TRUE){
//        return true;
//    }
//    return false;
    return rect.hayColision(b);
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
//    printf("seleccionado: %i\n", unidad.getId());
//    printf("cantidad seleccionados:%i \n", seleccionadas.size());
}

void SelectBox::vaciarSeleccionadas() {
    std::for_each(seleccionadas.begin(), seleccionadas.end(), []
        (ElementoUnidad &unidad){
//      unidad.deseleccionar();
    });
    seleccionadas.clear();
}

bool SelectBox::haySeleccion() {
    return !seleccionadas.empty();
}

const std::vector<ElementoUnidad> &SelectBox::getSeleccionadas() const {
    return seleccionadas;
}
