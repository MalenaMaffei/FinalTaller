#include "Header Files/GuiEdificio.h"
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

GuiEdificio::GuiEdificio(SDL_Renderer *gRenderer)
    : vistaGui(VistaGui(gRenderer)),vistaTexto(VistaTexto(gRenderer)),
      barraConstr(ProgressBar(7,37,gRenderer,{3,91,11}, {223,175,75})),
      seMuestra(false),tipoSeleccionado(-1),posSeleccionada(0){
        relPosCANCEL = {{CANCEL_RELX, CANCEL_RELY}, WIDTH_BUTTON,HEIGHT_BUTTON};
        relPosNEXT = {{ARROW_RELX, ARROW_RELY}, WIDTH_ARROW,HEIGHT_ARROW};
        relPosOK = {{OK_RELX, OK_RELY}, WIDTH_BUTTON, HEIGHT_BUTTON};
        posUNIT = {UNIT_RELX, UNIT_RELY};
        posVida = {VIDA_RELX, VIDA_RELY};
        posNombre = {5,7};
        vistaTexto.loadFont(fuentePath, 12);

//        tiposConstruibles = {6,7,8,9,10,11,12,13,14,15,16};
}

void GuiEdificio::mostrar(Camara &camara) {
    if (seMuestra && camara.checkCollision(Rect(position, vistaGui.getWidth()
        , vistaGui.getHeight()))){
        Punto offset = camara.getOffset();
        Punto pReal = position - offset;
        cancel = relPosCANCEL.positiveShift(position);
        ok = relPosOK.positiveShift(position);
        next = relPosNEXT.positiveShift(position);
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
            barraConstr.mostrarVertical(porcentajeConstruido, pReal +
                Punto(CONSTR_RELX, CONSTR_RELY));
//            TODO mensaje "en construccion"
        }

//        TODO elegir label de la fabrica para poner
    }
}

void GuiEdificio::abrirGui(Punto pos, std::string id) {
    resetSeleccion();
    idFabrica = id;
    position = pos;
//    seMuestra = true;
}

bool GuiEdificio::click(Punto click) {
    if (cancel.incluyePunto(click)){
        resetSeleccion();
        seMuestra = false;
    } else if (ok.incluyePunto(click)){
        seMuestra = false;
        tipoSeleccionado = tiposConstruibles[posSeleccionada];
    } else if (next.incluyePunto(click)){
        ++posSeleccionada;
        posSeleccionada %= tiposConstruibles.size();
    } else {
        return false;
    }
    return true;
}

void GuiEdificio::resetSeleccion() {
    tipoSeleccionado = -1;
    posSeleccionada = 0;
}

int GuiEdificio::getTipoSeleccionado() const {
    return tipoSeleccionado;
}

bool GuiEdificio::huboSeleccion() const {
    return tipoSeleccionado >= 0;
}

std::string GuiEdificio::getIdFabrica() const {
    return idFabrica;
}

void GuiEdificio::setInfo(PaqueteFabrica paquete) {
    tiemposConstruibles = paquete.getConstruibles();
    tiposConstruibles.clear();
    for (const auto& kv : tiemposConstruibles) {
        tiposConstruibles.push_back(kv.first);
    }
    vida = paquete.getVidaFabrica() + "%";
    tipoFabrica = paquete.getTipoFabrica();
    if (paquete.estaConstruyendo()){
        hayEnConstruccion = true;
        float cienporciento = 100;
        porcentajeConstruido = paquete.porcentajeConstruido()/cienporciento;
        tipoEnConstruccion = paquete.tipoEnConstruccion();
    } else {
        hayEnConstruccion = false;
    }
    seMuestra = true;
}
