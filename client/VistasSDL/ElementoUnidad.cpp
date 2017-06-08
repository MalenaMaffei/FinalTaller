#include "Header Files/ElementoUnidad.h"
#include "Header Files/VistaDireccionada.h"
#include "Header Files/SelectBox.h"
#include "Header Files/ColectorDeAcciones.h"
ElementoUnidad::ElementoUnidad(std::string id,
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
    direccion = rect.getPunto().calcularDireccion(nuevo);
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


void ElementoUnidad::avanzarMuerte() {
    if (vistaMuerte->isLastClip(currentClip)){
        estado = haciendoNada;
        muerto = true;
        printf("%i se murio\n", id);
        return;
    }
    ++currentClip;
    currentClip = vistaMuerte->getClip(currentClip);
}

void ElementoUnidad::avanzarDisparo() {
    printf("current clip: %i\n", currentClip);
    if (vistaDisparar->isLastClip(currentClip, 0)){
        estado = haciendoNada;
        textura = vistaMovimiento;
        currentClip = 0;
        vistaMovimiento->getClip(currentClip, direccion);
        return;
    }

    currentClip = vistaDisparar->getClip(currentClip, direccion);
    ++currentClip;
}

void ElementoUnidad::disparar(Punto target) {
    currentClip = 0;
    estado = disparando;
    textura = vistaDisparar;
    direccion = rect.getPunto().calcularDireccion(target);
//    currentClip = vistaDisparar->getClip(currentClip, direccion);
    printf("direccion: %i\n", direccion);
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
        avanzarMuerte();
        return;
    } else if (estado == disparando){
        avanzarDisparo();
    }
    ElementoColoreado::mostrar(camera);
}

void ElementoUnidad::chequearSeleccion(SelectBox &selectBox) {
    if (estado != muriendo && !muerto){
        if (selectBox.checkCollision(rect) && Mio){
            selectBox.selectUnidad(*this);
        }
    }
}

void ElementoUnidad::guiRequest(ColectorDeAcciones &colector) const {
    colector.showHud();
}

//TODO clicked polimorfizar
