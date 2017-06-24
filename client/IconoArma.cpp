#include "IconoArma.h"
#include "Header Files/VistaIconoArma.h"
#include "PaqueteUnidad.h"
#define X 0
#define Y 144

IconoArma::IconoArma(SDL_Renderer *gRenderer) : ElementoGui(new VistaIconoArma(
    gRenderer), Punto(X,Y)) {
    labels[codigos.grunt] = labelGrunt;
    labels[codigos.laser] = labelLaser;
    labels[codigos.psycho] = labelPsycho;
    labels[codigos.pyro] = labelPyro;
    labels[codigos.sniper] = labelSniper;
    labels[codigos.tough] = labelTough;
}

void IconoArma::setInfo(Paquete paquete) {
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    int tipo = paqueteUnidad.getTipo();
    if (codigos.esRobot(tipo)){
        clip = labels.at(tipo);
        seMuestra = true;
    } else{
        seMuestra = false;
    }
}

