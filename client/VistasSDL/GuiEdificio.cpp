#include "GuiEdificio.h"
GuiEdificio::GuiEdificio(Vista &vistaGui) : vistaGui(vistaGui), seMuestra(false) {
    cancel = {-1,-1,0,0};
    ok = {-1,-1,0,0};
    next = {-1,-1,0,0};
}

void GuiEdificio::mostrar(SDL_Point offset) {
    if(seMuestra){
        int xReal = position.x-offset.x;
        int yReal = position.y-offset.y;
        cancel = {xReal+67, yReal + 47, 40, 14};
        ok = {xReal+67, yReal + 61, 40, 13};
        vistaGui.mostrar(xReal,yReal,0);
    }

}

void GuiEdificio::abrirGui(SDL_Point pos) {
    seMuestra = true;
    position = pos;
}

bool GuiEdificio::click(SDL_Point click) {
    if (SDL_PointInRect(&click, &cancel)){
        seMuestra = false;
        return true;
    } else if(SDL_PointInRect(&click, &ok)){
        seMuestra = false;
        printf("se apreto ok en gui crear\n");
        return true;
    }
}
