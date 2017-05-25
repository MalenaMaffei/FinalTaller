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

void SelectBox::setRect(const SDL_Rect &rect) {
    SelectBox::rect = rect;
}

bool SelectBox::checkCollision(SDL_Rect b) {
//    int leftA, leftB;
//    int rightA, rightB;
//    int topA, topB;
//    int bottomA, bottomB;
//
//    //Calculate the sides of rect A
//    leftA = rect.x;
//    rightA = rect.x + rect.w;
//    topA = rect.y;
//    bottomA = rect.y + rect.h;
//
//    //Calculate the sides of rect B
//    leftB = b.x;
//    rightB = b.x + b.w;
//    topB = b.y;
//    bottomB = b.y + b.h;
//
//    //If any of the sides from A are outside of B
//    if( bottomA <= topB )
//    {
////        printf("bottomA <= topB:%i, %i  \n", bottomA, topB);
//        return false;
//    }
//
//    if( topA >= bottomB )
//    {
////        printf("topA >= bottomB \n");
//        return false;
//    }
//
//    if( rightA <= leftB )
//    {
////        printf("rightA <= leftB \n");
//        return false;
//    }
//
//    if( leftA >= rightB )
//    {
////        printf("leftA >= rightB \n");
//        return false;
//    }
//
//    //If none of the sides from A are outside B
//    return true;
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
