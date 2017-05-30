#include "GuiEdificio.h"
GuiEdificio::GuiEdificio(Vista &vistaGui) : vistaGui(vistaGui), seMuestra(false) {}

void GuiEdificio::mostrar(SDL_Point offset) {
    if(seMuestra){
        vistaGui.mostrar(position.x-offset.x,position.y-offset.y,0);
    }

}

void GuiEdificio::abrirGui(SDL_Point pos) {
    seMuestra = true;
    position = pos;
}
