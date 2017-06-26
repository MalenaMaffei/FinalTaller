#include "Header Files/SelectBox.h"
#include <algorithm>
#include <vector>
void SelectBox::mostrar(SDL_Renderer *renderer, Punto offset) {
    SDL_SetRenderDrawColor(renderer , 0 , 255 , 0 , 255);
    Rect displayRect = rect.negativeShift(offset);

    SDL_RenderDrawRect(renderer, &displayRect);
    seleccionadas.erase(std::remove_if(seleccionadas.begin(),
        seleccionadas.end(),[](ElementoUnidad* unidad) {
                return unidad->estaMuriendo();}), seleccionadas.end());

    std::for_each(seleccionadas.begin(), seleccionadas.end(), [&]
        (ElementoUnidad* unidad){
            displayRect = unidad->getRect().negativeShift(offset);
            SDL_RenderDrawRect(renderer, &displayRect);
    });
}

SelectBox::SelectBox() {
//    rect.x = 0;
//    rect.y = 0;
//    rect.w = 0;
//    rect.h = 0;
}

void SelectBox::setRect(const Rect &rect) {
    SelectBox::rect = rect;
}

bool SelectBox::checkCollision(Rect b) {
    return rect.hayColision(b);
}

int SelectBox::getX() {
    return rect.x;
}

int SelectBox::getY() {
    return rect.y;
}

void SelectBox::selectUnidad(ElementoUnidad *unidad) {
    seleccionadas.push_back(unidad);
}

void SelectBox::vaciarSeleccionadas() {
    seleccionadas.clear();
}

bool SelectBox::haySeleccion() {
    return !seleccionadas.empty();
}

const std::vector<ElementoUnidad*> &SelectBox::getSeleccionadas() const {
    return seleccionadas;
}
