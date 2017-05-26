#include "ElementoUnidad.h"
#include "VistaDireccionada.h"
#include "SelectBox.h"
ElementoUnidad::ElementoUnidad(int id,
                               int x,
                               int y,
                               VistaDireccionada *textura,
                               Vista *vistaMuerte) :
    Elemento(id, x, y, textura, false),
    vistaMovimiento(textura), enMovimiento(false), direccion(0), muriendo
        (false), vistaMuerte(vistaMuerte){}


void ElementoUnidad::mover(int newX, int newY) {
    int shiftX = rect.x - newX;
    int shiftY = rect.y - newY;
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

    rect.x = newX;
    rect.y = newY;

    if (!enMovimiento){
        currentClip = 0;
        enMovimiento = true;
        textura = vistaMovimiento;
    } else {
        ++currentClip;
    }
    currentClip = vistaMovimiento->getClip(currentClip, direccion);
}

//TODO terminar de refactorizar bien aca para usar esto para tanques y
// robots, tambien revisar el tema de las texturas!



void ElementoUnidad::morir() {
    if (vistaMuerte->isLastClip(currentClip)){
        muriendo = false;
        muerto = true;
        return;
    }
    ++currentClip;
    currentClip = vistaMuerte->getClip(currentClip);
}

void ElementoUnidad::matar() {
    if (muriendo || estaMuerto() ){
        return;
    }
    currentClip = 0;
    muriendo = true;
    enMovimiento = false;
    disparando = false;
    textura = vistaMuerte;
}

void ElementoUnidad::mostrar(Camara &camera) {
    Elemento::mostrar(camera);
    if (muriendo){
        morir();
    }
}

void ElementoUnidad::chequearSeleccion(SelectBox &selectBox) {
    if(!muerto){
        if( selectBox.checkCollision( rect )){
            //Show the tile
//            textura->setColor(0,255,0);
            selectBox.selectUnidad(*this);
        } else {
//            textura->setColor(255,255,255);
        }
    }
}

void ElementoUnidad::seleccionar() {
    textura->setColor(0,255,0);
}

void ElementoUnidad::deseleccionar() {
    textura->setColor(255,255,255);
}

