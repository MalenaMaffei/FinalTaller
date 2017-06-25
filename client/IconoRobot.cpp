#include "IconoRobot.h"
#include "Header Files/VistaIconoRobot.h"
#include "PaqueteUnidad.h"
#define X 8
#define Y 46
IconoRobot::IconoRobot(SDL_Renderer *gRenderer) : ElementoGui(new
                                                                  VistaIconoRobot(
    gRenderer), Punto(X,Y)) {
    labels[codigos.grunt] = labelGrunt;
    labels[codigos.laser] = labelLaser;
    labels[codigos.psycho] = labelPsycho;
    labels[codigos.pyro] = labelPyro;
    labels[codigos.sniper] = labelSniper;
    labels[codigos.tough] = labelTough;
}

void IconoRobot::setInfo(Paquete paquete) {
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    int tipo = paqueteUnidad.getTipo();
    if (codigos.esRobot(tipo)){
        clip = labels.at(tipo);
        clip = vista->getClip(clip,paqueteUnidad.getColor());
        seMuestra = true;
    } else if (codigos.esVehiculo(tipo)){
        clip = labels.at(codigos.grunt);

        clip = vista->getClip(clip,paqueteUnidad.getColor());
        seMuestra = true;
    } else{
        seMuestra = false;
    }
}

