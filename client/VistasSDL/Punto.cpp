#include "Punto.h"
Punto Punto::operator+(Punto &otro) {
    Punto nuevo;
    x = x + otro.x;
    y = y + otro.y;
    return nuevo;
}

Punto Punto::operator-(Punto &otro) {
    Punto nuevo;
    nuevo.x = x - otro.x;
    nuevo.y = y - otro.y;
    return nuevo;
}
Punto::Punto() {

}
