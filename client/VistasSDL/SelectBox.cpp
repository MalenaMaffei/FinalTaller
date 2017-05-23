#include "SelectBox.h"

void SelectBox::mostrar(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer , 0 , 255 , 0 , 255);
    SDL_RenderDrawRect(renderer, &rect);
}

SelectBox::SelectBox(int x, int y, int w, int h, int filled) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}
