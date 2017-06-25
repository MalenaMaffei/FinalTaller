#include "IconoVehiculo.h"
#include "Header Files/VistaIconoVehiculo.h"
#include "PaqueteUnidad.h"
#define X 0
#define Y 148
IconoVehiculo::IconoVehiculo(SDL_Renderer *gRenderer) :
    ElementoGui(new VistaIconoVehiculo(gRenderer), Punto(X,Y)) {
    labels[codigos.heavy] = labelHeavy;
    labels[codigos.jeep] = labelJeep;
    labels[codigos.light] = labelLight;
    labels[codigos.medium] = labelMedium;
    labels[codigos.missile] = labelMissile;
}

void IconoVehiculo::setInfo(Paquete paquete) {
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    int tipo = paqueteUnidad.getTipo();
    if (codigos.esVehiculo(tipo)){
        clip = labels.at(tipo);
        clip = vista->getClip(clip,paqueteUnidad.getColor());
        seMuestra = true;
    } else{
        seMuestra = false;
    }
}
