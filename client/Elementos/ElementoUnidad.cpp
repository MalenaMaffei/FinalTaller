#include "../Header Files/ElementoUnidad.h"
#include "../Header Files/VistaDireccionada.h"
#include "../Header Files/SelectBox.h"
#include "../Header Files/ColectorDeAcciones.h"
#include <string>
ElementoUnidad::ElementoUnidad(std::string id,
                               Punto pos,
                               VistaDireccionada *movimiento,
                               VistaDireccionada *disparar,
                               Vista *vistaMuerte,
                               bool esMio,
                               int color) :
    ElementoColoreado(id, pos, movimiento, esMio, color),
    vistaMovimiento(movimiento), vistaDisparar(disparar), direccion(0),
        estado(haciendoNada), vistaMuerte(vistaMuerte){}


void ElementoUnidad::mover(Punto nuevo) {
//    direccion = rect.getCentro().calcularDireccion(nuevo);
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

void ElementoUnidad::avanzarMuerte() {
    if (vistaMuerte->isLastClip(currentClip)){
        estado = haciendoNada;
        muerto = true;
        return;
    }
    ++currentClip;
    currentClip = vistaMuerte->getClip(currentClip);
}

void ElementoUnidad::avanzarDisparo() {
    if (vistaDisparar->isLastClip(currentClip, 0)){
        estado = haciendoNada;
        textura = vistaMovimiento;
        currentClip = 0;
        currentClip = vistaMovimiento->getClip(currentClip, direccion);
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
}

void ElementoUnidad::matar() {
    if (estado == muriendo || estaMuerto()){
        return;
    }
    currentClip = 0;
    estado = muriendo;
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
            selectBox.selectUnidad(this);
        }
    }
}

void ElementoUnidad::guiRequest(ColectorDeAcciones &colector) const {
    colector.showHud(id, color);
}

bool ElementoUnidad::estaMuriendo() {
    return estado == muriendo;
}
