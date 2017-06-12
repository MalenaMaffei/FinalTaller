#include "Header Files/GuiEdificio.h"
#define OFF_CANCEL_X 67
#define OFF_CANCEL_Y 47
#define OFF_OK_X 67
#define OFF_OK_Y 61
GuiEdificio::GuiEdificio(Vista &vistaGui) : vistaGui(vistaGui),
                                            seMuestra(false) {}

void GuiEdificio::mostrar(Punto offset) {
    if (seMuestra){
        Punto pReal = position - offset;
//        TODO sacar numeros magicos
        cancel = Rect(pReal + Punto(OFF_CANCEL_X, OFF_CANCEL_Y), 40, 14);
        ok = Rect(pReal + Punto(OFF_OK_X, OFF_OK_Y), 40, 13);
        printf("ok vive en: %i, %i\n", ok.x, ok.y );
        printf("cancel vive en: %i, %i\n", cancel.x, cancel.y );
        vistaGui.mostrar(pReal, 0);
    }
}

void GuiEdificio::abrirGui(Punto pos) {
    seMuestra = true;
    position = pos;
}

bool GuiEdificio::click(Punto click) {
//    printf("click en: %i,%i\n", click.x, click.y);

    if (cancel.incluyePunto(click)){
        seMuestra = false;
        return true;
    } else if (ok.incluyePunto(click)){
        seMuestra = false;
        printf("se apreto ok en gui crear\n");
        return true;
    }
}
