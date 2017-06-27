#include "Header Files/GuiFabrica.h"
#include "Header Files/VistaGui.h"
#include "Header Files/constantes.h"
#include "Header Files/common_CodigosPaquete.h"
#include <string>
#define CANCEL_RELX 67
#define CANCEL_RELY 47
#define OK_RELX 67
#define OK_RELY 61
#define HEIGHT_BUTTON 14
#define WIDTH_BUTTON 40
#define HEIGHT_ARROW 8
#define WIDTH_ARROW 11
#define ARROW_RELX 52
#define ARROW_RELY 65
#define UNIT_RELX 7
#define UNIT_RELY 58
#define VIDA_RELX 84
#define VIDA_RELY 4
#define TIEMPO_RELX 73
#define TIEMPO_RELY 32
#define CONSTR_RELX 54
#define CONSTR_RELY 22
using std::string;

GuiFabrica::GuiFabrica(SDL_Renderer *gRenderer,
                         VistaTexto &vistaTexto)
    : vistaGui(VistaGui(gRenderer)),
//      vistaTexto(VistaTexto(gRenderer)),
      vistaTexto(vistaTexto),
      barraConstr(ProgressBar(gRenderer,
                              {3, 91, 11},
                              {223, 175, 75},
                              Rect({CONSTR_RELX, CONSTR_RELY}, 7,37),
                              true)),
      seMuestra(false),tipoSeleccionado(-1),posSeleccionada(0),
      ok(Boton({OK_RELX, OK_RELY}, WIDTH_BUTTON, HEIGHT_BUTTON)),
      cancel(Boton({CANCEL_RELX, CANCEL_RELY}, WIDTH_BUTTON,HEIGHT_BUTTON)),
      next(Boton({ARROW_RELX, ARROW_RELY}, WIDTH_ARROW,HEIGHT_ARROW)),
      esperandoInfo(false), gallery(FactoryGallery(gRenderer, {5,6})){
        posUNIT = {UNIT_RELX, UNIT_RELY};
        posVida = {VIDA_RELX, VIDA_RELY};
        posNombre = {5,7};
        vistaTexto.loadFont(fuentePath, 12);

//        tiposConstruibles = {6,7,8,9,10,11,12,13,14,15,16};
}

void GuiFabrica::mostrar(Camara &camara) {
    if (seMuestra && camara.estaEnfocado(Rect(position,
                                              vistaGui.getWidth(),
                                              vistaGui.getHeight()))){
        Punto offset = camara.getPos();
        Punto pReal = position - offset;
        cancel.ubicar(position);
        ok.ubicar(position);
        next.ubicar(position);
        vistaGui.mostrar(pReal, 0);
        CodigosPaquete codigos;

        int tipoSeleccionado = tiposConstruibles[posSeleccionada];

        string nombreUnidad = codigos.nombreUnidad(tipoSeleccionado);
        vistaTexto.mostrar(nombreUnidad, {255,255,255}, pReal + posUNIT);
        vistaTexto.mostrar(vida, {255,255,255}, pReal + posVida);
        string tiempo = tiemposConstruibles.at(tipoSeleccionado);
        vistaTexto.mostrar(tiempo, {255,255,255}, pReal + Punto(TIEMPO_RELX,
                                                           TIEMPO_RELY));
        if (hayEnConstruccion && tipoSeleccionado == tipoEnConstruccion){
            barraConstr.mostrar(pReal);
        }
        gallery.mostrar(pReal);
    }
}

void GuiFabrica::abrirGui(Punto pos, std::string id) {
    resetSeleccion();
    idFabrica = id;
    position = pos;
    esperandoInfo = true;
}

bool GuiFabrica::click(Punto click) {
    if (cancel.wasPressed(click)){
        resetSeleccion();
        seMuestra = false;
        esperandoInfo = false;
    } else if (ok.wasPressed(click)){
        seMuestra = false;
        esperandoInfo = false;
        tipoSeleccionado = tiposConstruibles[posSeleccionada];
    } else if (next.wasPressed(click)){
        ++posSeleccionada;
        posSeleccionada %= tiposConstruibles.size();
    } else {
        return false;
    }
    return true;
}

void GuiFabrica::resetSeleccion() {
    tipoSeleccionado = -1;
    posSeleccionada = 0;
}

int GuiFabrica::getTipoSeleccionado() const {
    return tipoSeleccionado;
}

bool GuiFabrica::huboSeleccion() const {
    return tipoSeleccionado >= 0;
}

std::string GuiFabrica::getIdFabrica() const {
    return idFabrica;
}

void GuiFabrica::setInfo(PaqueteFabrica paquete) {
    if (!esperandoInfo){
        return;
    }
    tiemposConstruibles = paquete.getConstruibles();
    tiposConstruibles.clear();
    for (const auto& kv : tiemposConstruibles) {
        tiposConstruibles.push_back(kv.first);
    }
    vida = paquete.getVidaFabrica() + "%";
    tipoFabrica = paquete.getTipoFabrica();
    if (paquete.estaConstruyendo()){
        hayEnConstruccion = true;
        barraConstr.setInfo(paquete.porcentajeConstruido());
        tipoEnConstruccion = paquete.tipoEnConstruccion();
    } else {
        hayEnConstruccion = false;
    }
    gallery.setInfo(tipoFabrica);
    seMuestra = true;
}

bool GuiFabrica::activo() {
    return seMuestra;
}

GuiFabrica::~GuiFabrica() {}
