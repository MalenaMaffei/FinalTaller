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
    mostrarContenido();

}

//TODO TANQUE SI ESTA CON ALGUIEN ES SIEMPRE UN GRUNT!!!
//tTODO fabricas tienen qeu ser mias

//TODO todos los turnos pido info del id seleccionado
//TODO en realidad me va a llegar un paquete y el me dira que hacer
void Hud::setInfo(int tipo) {
    tipoCara = tipo;
    seleccionado = true;
}

void Hud::mostrarContenido() {
//    TODO IF CARA IF ESTO IF LO OTRO
}
