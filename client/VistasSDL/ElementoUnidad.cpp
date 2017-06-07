#include "Header Files/ElementoUnidad.h"
#include "Header Files/VistaDireccionada.h"
#include "Header Files/SelectBox.h"
#include "Header Files/ColectorDeAcciones.h"
ElementoUnidad::ElementoUnidad(int id,
                               int x,
                               int y,
                               VistaDireccionada *movimiento,
                               VistaDireccionada *disparar,
                               Vista *vistaMuerte,
                               bool esMio,
                               int color) :
        ElementoColoreado(id, x, y, movimiento, esMio, color),
    vistaMovimiento(movimiento), vistaDisparar(disparar), direccion(0),
        estado(haciendoNada), vistaMuerte(vistaMuerte){}


void ElementoUnidad::mover(Punto nuevo) {
//    int shiftX = rect.x - newX;
//    int shiftY = rect.y - newY;
//    Punto nuevo(newX, newY);
    Punto shift = rect.getPunto() - nuevo;
//    TODO horrible, crear clase coordenada
    if (shift.x > 0){
        if (shift.y > 0){
//            direccion = 3;
            direccion = noroeste;
        } else if (shift.y == 0){
//            direccion = 4;
            direccion = oeste;
        } else if (shift.y < 0){
//            direccion = 5;
            direccion = suroeste;
        }
    } else if (shift.x == 0){
        if (shift.y > 0){
//            direccion = 2;
            direccion = norte;
        } else if (shift.y == 0){
            estado = haciendoNada;
            return;
        } else if (shift.y < 0){
//            direccion = 6;
            direccion = sur;
        }
    } else if (shift.x < 0){
        if (shift.y > 0){
//            direccion = 1;
            direccion = noreste;
        } else if (shift.y == 0){
//            direccion = 0;
            direccion = este;
        } else if (shift.y < 0){
//            direccion = 7;
            direccion = sureste;
        }
    }

//    rect.x = newX;
//    rect.y = newY;
    rect.setPunto(nuevo);

    if (estado != enMovimiento) {
        currentClip = 0;
        estado = enMovimiento;
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
        estado = haciendoNada;
        muerto = true;
        printf("%i se murio\n", id);
        return;
    }
    ++currentClip;
    currentClip = vistaMuerte->getClip(currentClip, 0);
}

void ElementoUnidad::matar() {
    if (estado == muriendo || estaMuerto()){
        return;
    }
    currentClip = 0;
    estado = muriendo;
//    muriendo = true;
//    enMovimiento = false;
//    disparando = false;
    textura = vistaMuerte;
}

void ElementoUnidad::mostrar(Camara &camera) {
    if (estado == muriendo){
        Elemento::mostrar(camera);
        morir();
    } else {
        ElementoColoreado::mostrar(camera);
    }
}

void ElementoUnidad::chequearSeleccion(SelectBox &selectBox) {
    if (estado != muriendo && !muerto){
        if (selectBox.checkCollision(rect) && Mio){
            selectBox.selectUnidad(*this);
        }
    }
}

//void ElementoUnidad::seleccionar() {
//    textura->setColor(0,255,0);
//}
//
//void ElementoUnidad::deseleccionar() {
//    textura->setColor(255,255,255);
//}

void ElementoUnidad::guiRequest(ColectorDeAcciones &colector) const {
    colector.showHud();
}

void ElementoUnidad::disparar() {
//    TODO terminar disparar
}

//TODO clicked polimorfizar
