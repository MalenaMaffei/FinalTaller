#include "Punto.h"
Punto Punto::operator+(Punto &otro) {
    Punto nuevo(0, 0);
    nuevo.x = x + otro.x;
    nuevo.y = y + otro.y;
    return nuevo;
}

Punto Punto::operator-(Punto &otro) {
    Punto nuevo(0, 0);
    nuevo.x = x - otro.x;
    nuevo.y = y - otro.y;
    return nuevo;
}

Punto::Punto(int x, int y) {
    this->x = x;
    this->y = y;
}
