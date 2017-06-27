#include "LabelRobot.h"
#include "../../Header Files/VistaLabelRobot.h"
#include "../../Header Files/PaqueteUnidad.h"
#include <map>
#define X 3
#define Y 124
LabelRobot::LabelRobot(SDL_Renderer *gRenderer) : ElementoGui
                                                      (new VistaLabelRobot(
                                                          gRenderer), Punto
                                                          (X,Y)) {
    labels[codigos.grunt] = labelGrunt;
    labels[codigos.laser] = labelLaser;
    labels[codigos.psycho] = labelPsycho;
    labels[codigos.pyro] = labelPyro;
    labels[codigos.sniper] = labelSniper;
    labels[codigos.tough] = labelTough;
}

void LabelRobot::setInfo(PaqueteAccion paquete) {
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    int tipo = paqueteUnidad.getTipo();
    if (codigos.esRobot(tipo)){
        clip = labels.at(tipo);
        seMuestra = true;
    } else if (codigos.esVehiculo(tipo)){
        clip = labels.at(codigos.grunt);
        seMuestra = true;
    } else{
        seMuestra = false;
    }
}
