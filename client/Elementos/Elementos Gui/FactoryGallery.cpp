#include "../../Header Files/FactoryGallery.h"
#include "../../Header Files/VistaLabelFabrica.h"
FactoryGallery::FactoryGallery(SDL_Renderer *gRenderer, const Punto &relPos) :
    GuiGallery(new VistaLabelFabrica(gRenderer),relPos) {
    seMuestra = true;
    labels[codigos.fuerte] = labelFuerte;
    labels[codigos.fabricaVehiculo] = labelFabVehiculo;
    labels[codigos.fabricaRobot] = labelFabRobot;
}

void FactoryGallery::setInfo(int tipo) {
    clip = labels.at(tipo);
}
