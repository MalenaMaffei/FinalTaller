#include "LabelVehiculo.h"
#include "Header Files/VistaLabelVehiculo.h"
#include "Header Files/PaqueteUnidad.h"
#define X 2
#define Y 230
LabelVehiculo::LabelVehiculo(SDL_Renderer *gRenderer) :
    ElementoGui(new VistaLabelVehiculo(gRenderer), Punto(X,Y)) {
    labels[codigos.heavy] = labelHeavy;
    labels[codigos.jeep] = labelJeep;
    labels[codigos.light] = labelLight;
    labels[codigos.medium] = labelMedium;
    labels[codigos.missile] = labelMissile;
}

void LabelVehiculo::setInfo(PaqueteAccion paquete) {
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    int tipo = paqueteUnidad.getTipo();
    if (codigos.esVehiculo(tipo)){
        clip = labels.at(tipo);
        seMuestra = true;
    } else{
        seMuestra = false;
    }
}
