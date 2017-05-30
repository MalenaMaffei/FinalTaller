#include "Hud.h"
#include "constantes.h"


Hud::Hud(Vista &hud, Vista &vistaCaras) : vistaHud(hud), vistaCaras(vistaCaras) {
    x = SCREEN_WIDTH - hud.getWidth();
    y = 0;
    hudRect = {x,y,hud.getWidth(),hud.getHeight()};
}

void Hud::mostrar() {
    vistaHud.mostrar(x,y,0);
    vistaCaras.mostrar(x+9,y+58,0);
}
//TODO todos los turnos pido info del id seleccionado
//TODO en realidad me va a llegar un paquete y el me dira que hacer
void Hud::setCara(int tipo) {
    tipoCara = tipo;
}
