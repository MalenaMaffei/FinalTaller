#include "RobotGallery.h"
#include "../../Header Files/VistaIconoRobot.h"
#include "../../Header Files/PaqueteUnidad.h"
#define X 8
#define Y 46
RobotGallery::RobotGallery(Vista *vista,
                           Punto relPos) : GuiGallery(vista, relPos) {
    labels[codigos.grunt] = labelGrunt;
    labels[codigos.laser] = labelLaser;
    labels[codigos.psycho] = labelPsycho;
    labels[codigos.pyro] = labelPyro;
    labels[codigos.sniper] = labelSniper;
    labels[codigos.tough] = labelTough;
}

void RobotGallery::setInfo(PaqueteUnidad paquete) {
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

