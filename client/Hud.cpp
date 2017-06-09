#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#define X_CARA 9
#define Y_CARA 58

Hud::Hud(Vista &hud, Vista &vistaCaras) : vistaHud(hud), vistaCaras
    (vistaCaras), seleccionado(false), ubicacion(SCREEN_WIDTH - hud.getWidth(), 0) {
    hudRect = {ubicacion,hud.getWidth(),hud.getHeight()};
}

void Hud::mostrar() {
    vistaHud.mostrar(ubicacion, 0);
    mostrarContenido();
//    TODO sacar despues
    if (seleccionado){
        printf("hubo seleccion\n");
//        TODO hacer esto atributo
        Punto caraOffset(X_CARA,Y_CARA);
        Punto caraPos = ubicacion + caraOffset;
        vistaCaras.mostrar(caraPos, 0);
    }
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
