#include "../../Header Files/VehiculoGallery.h"
#include "../../Header Files/VistaIconoVehiculo.h"
#include "../../Header Files/PaqueteUnidad.h"
#define X 0
#define Y 148
VehiculoGallery::VehiculoGallery(Vista *vista,Punto relPos) :
                                    GuiGallery(vista, relPos) {
    labels[codigos.heavy] = labelHeavy;
    labels[codigos.jeep] = labelJeep;
    labels[codigos.light] = labelLight;
    labels[codigos.medium] = labelMedium;
    labels[codigos.missile] = labelMissile;
}

void VehiculoGallery::setInfo(PaqueteUnidad paquete) {
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
