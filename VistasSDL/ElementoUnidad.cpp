#include "ElementoUnidad.h"
#include "VistaDireccionada.h"
ElementoUnidad::ElementoUnidad(int id, int x,int y,VistaDireccionada *textura) :
    Elemento(id, x, y, textura),
    texturaDireccionada(textura), enMovimiento(false), direccion(0){}


void ElementoUnidad::mover(int newX, int newY) {
    int shiftX = mBox.x - newX;
    int shiftY = mBox.y - newY;
//    TODO horrible, crear clase coordenada
    if (shiftX > 0){
        if (shiftY > 0){
            direccion = 3;
        } else if (shiftY == 0){
            direccion = 4;
        } else if (shiftY < 0){
            direccion = 5;
        }
    } else if (shiftX == 0){
        if (shiftY > 0){
            direccion = 2;
        } else if (shiftY == 0){
            enMovimiento = false;
            return;
        } else if (shiftY < 0){
            direccion = 6;
        }
    } else if (shiftX < 0){
        if (shiftY > 0){
            direccion = 1;
        } else if (shiftY == 0){
            direccion = 0;
        } else if (shiftY < 0){
            direccion = 7;
        }
    }

    mBox.x = newX;
    mBox.y = newY;

    if (!enMovimiento){
        currentClip = 0;
        enMovimiento = true;

    } else {
        ++currentClip;
    }
    currentClip = texturaDireccionada->getClip(currentClip, direccion);
}

