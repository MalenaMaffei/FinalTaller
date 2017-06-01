#include "Header Files/Rect.h"
#include "Header Files/Punto.h"
Rect::Rect(Punto p, int width, int height) {
    x = p.x;
    y = p.y;
    w = width;
    h = height;
}

bool Rect::incluyePunto(Punto p) {
    return SDL_PointInRect(&p, this);
}

bool Rect::hayColision(Rect otro) {
    return  SDL_HasIntersection(this, &otro);
}

Punto Rect::getPunto() {
    return Punto(x, y);
}
