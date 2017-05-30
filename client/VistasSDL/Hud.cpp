#include "Hud.h"
#include "constantes.h"
#define X_CARA 9
#define Y_CARA 58

Hud::Hud(Vista &hud, Vista &vistaCaras) : vistaHud(hud), vistaCaras
    (vistaCaras), seleccionado(false) {
    x = SCREEN_WIDTH - hud.getWidth();
    y = 0;
    hudRect = {x,y,hud.getWidth(),hud.getHeight()};
}

void Hud::mostrar() {
    vistaHud.mostrar(x,y,0);
    if (seleccionado){
        vistaCaras.mostrar(x+X_CARA,y+Y_CARA,0);
    }

}

//TODO todos los turnos pido info del id seleccionado
//TODO en realidad me va a llegar un paquete y el me dira que hacer
void Hud::setCara(int tipo) {
    tipoCara = tipo;
    seleccionado = true;
}
