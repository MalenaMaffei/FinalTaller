#include "Header Files/GuiEdificio.h"
#include "Header Files/VistaGui.h"
#include "Header Files/constantes.h"
#include "Header Files/common_CodigosPaquete.h"
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
#define OFF_UNIT_X 7
#define OFF_UNIT_Y 58

GuiEdificio::GuiEdificio(SDL_Renderer *gRenderer)
    : vistaGui(VistaGui(gRenderer)),
      vistaTexto(VistaTexto(gRenderer)),
      seMuestra(false),
      tipoSeleccionado(-1),
      posSeleccionada(0){
        offsetCANCEL = Punto(OFF_CANCEL_X, OFF_CANCEL_Y);
        offsetNEXT = Punto(OFF_ARROW_X, OFF_ARROW_Y);
        offsetOK = Punto(OFF_OK_X, OFF_OK_Y);
        offsetUNIT = Punto(OFF_UNIT_X, OFF_UNIT_Y);
        vistaTexto.loadFont(fuentePath, 12);

        tiposConstruibles = {6,7,8,9,10,11,12,13,14,15,16};
}

void GuiEdificio::mostrar(Punto offset) {
    if (seMuestra){
        Punto pReal = position - offset;
        cancel = Rect(position + offsetCANCEL, WIDTH_BUTTON, HEIGHT_BUTTON);
        ok = Rect(position + offsetOK, WIDTH_BUTTON, HEIGHT_BUTTON);
        next = Rect(position + offsetNEXT, WIDTH_ARROW,HEIGHT_ARROW);
        vistaGui.mostrar(pReal, 0);
        CodigosPaquete codigos;
        std::string nombreUnidad = codigos.nombreUnidad
            (tiposConstruibles[posSeleccionada]);
        vistaTexto.mostrar(nombreUnidad, {255,255,255}, pReal + offsetUNIT);
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
        tipoSeleccionado = tiposConstruibles[posSeleccionada];
//        Aca se tiene que crear un paquete de informacion.
        printf("se apreto ok en gui crear\n");
    } else if (next.incluyePunto(click)){
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
