#include "Header Files/GuiEdificio.h"
#define OFF_CANCEL_X 67
#define OFF_CANCEL_Y 47
#define OFF_OK_X 67
#define OFF_OK_Y 61
#define HEIGHT_BUTTON 14
#define WIDTH_BUTTON 40
#define HEIGHT_ARROW 8
#define WIDTH_ARROW 11
#define OFF_ARROW_X 52
#define OFF_ARROW_Y 65
GuiEdificio::GuiEdificio(Vista &vistaGui) : vistaGui(vistaGui),
                                            seMuestra(false),
                                            tipoSeleccionado(-1),
                                            posSeleccionada(0){}

void GuiEdificio::mostrar(Punto offset) {
    if (seMuestra){
        Punto pReal = position - offset;
//        TODO sacar todos esos puntos de otro lado
        cancel = Rect(position + Punto(OFF_CANCEL_X, OFF_CANCEL_Y), WIDTH_BUTTON, HEIGHT_BUTTON);
        ok = Rect(position + Punto(OFF_OK_X, OFF_OK_Y), WIDTH_BUTTON, HEIGHT_BUTTON);
        next = Rect(position + Punto(OFF_ARROW_X, OFF_ARROW_Y), WIDTH_ARROW,
                    HEIGHT_ARROW);
        vistaGui.mostrar(pReal, 0);
    }
}

void GuiEdificio::abrirGui(Punto pos, std::string id) {
    resetSeleccion();
    fabricaId = id;
    seMuestra = true;
    position = pos;
}

bool GuiEdificio::click(Punto click) {
    if (cancel.incluyePunto(click)){
        resetSeleccion();
        seMuestra = false;
    } else if (ok.incluyePunto(click)){
        seMuestra = false;
//        tipoSeleccionado = tiposConstruibles[posSeleccionada];
//        Aca se tiene que crear un paquete de informacion.
        printf("se apreto ok en gui crear\n");
    } else if (next.incluyePunto(click)){
//        TODO cilcar fotos aca
        ++posSeleccionada;
        posSeleccionada %= tiposConstruibles.size();
        printf("posSeleccionada: %i\n", posSeleccionada);
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

std::string GuiEdificio::getFabricaId() const {
    return fabricaId;
}
