#include "../../Header Files/ArmaGallery.h"
#include "../../Header Files/VistaIconoArma.h"
#include "../../Header Files/PaqueteUnidad.h"
#define X 0
#define Y 144

ArmaGallery::ArmaGallery(Vista *vista,Punto relPos) :
    GuiGallery(vista, relPos) {
    labels[codigos.grunt] = labelGrunt;
    labels[codigos.laser] = labelLaser;
    labels[codigos.psycho] = labelPsycho;
    labels[codigos.pyro] = labelPyro;
    labels[codigos.sniper] = labelSniper;
    labels[codigos.tough] = labelTough;
}

void ArmaGallery::setInfo(PaqueteUnidad paquete) {
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    int tipo = paqueteUnidad.getTipo();
    if (codigos.esRobot(tipo)){
        clip = labels.at(tipo);
        seMuestra = true;
    } else{
        seMuestra = false;
    }
}

