#include "Header Files/Punto.h"
Punto Punto::operator+(Punto otro) {
    Punto nuevo(0, 0);
    nuevo.x = x + otro.x;
    nuevo.y = y + otro.y;
    return nuevo;
}

Punto Punto::operator-(Punto otro) {
    Punto nuevo(0, 0);
    nuevo.x = x - otro.x;
    nuevo.y = y - otro.y;
    return nuevo;
}

Punto::Punto(int x, int y) {
    this->x = x;
    this->y = y;
}

int Punto::calcularDireccion(Punto otro) {
    Punto shift = *this - otro;
    if (shift.x > 0){
        if (shift.y > 0){
            return noroeste;
        } else if (shift.y == 0){
            return oeste;
        } else if (shift.y < 0){
            return suroeste;
        }
    } else if (shift.x == 0){
        if (shift.y > 0){
            return norte;
        } else if (shift.y == 0){
            return centro;
        } else if (shift.y < 0){
            return sur;
        }
    } else if (shift.x < 0){
        if (shift.y > 0){
            return noreste;
        } else if (shift.y == 0){
            return este;
        } else if (shift.y < 0){
            return sureste;
        }
    }
}

bool Punto::operator==(Punto otro) {
    return x == otro.x && y == otro.y;
}
