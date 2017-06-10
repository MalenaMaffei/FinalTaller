#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#define X_CARA 9
#define Y_CARA 58

Hud::Hud(Vista &hud, Vista &vistaCaras) : vistaHud(hud), vistaCaras
    (vistaCaras), seleccionado(false), ubicacion(SCREEN_WIDTH - hud.getWidth(), 0) {
    hudRect = {ubicacion,hud.getWidth(),hud.getHeight()};
}

void Hud::mostrar() {
    vistaHud.mostrar(ubicacion, 0);
    mostrarContenido();
//    TODO sacar despues
    if (seleccionado){
//        TODO hacer esto atributo
        Punto caraOffset(X_CARA,Y_CARA);
        Punto caraPos = ubicacion + caraOffset;
        vistaCaras.mostrar(caraPos, 0);
    }
}

//TODO TANQUE SI ESTA CON ALGUIEN ES SIEMPRE UN GRUNT!!!
//tTODO fabricas tienen qeu ser mias

//TODO todos los turnos pido info del id seleccionado
//TODO en realidad me va a llegar un paquete y el me dira que hacer
void Hud::setInfo(int tipo) {
    tipoCara = tipo;
    seleccionado = true;
}

void Hud::mostrarContenido() {
//    TODO IF CARA IF ESTO IF LO OTRO
}

//void Hud::RenderHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor) {
//    Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
//    SDL_Color old;
//    SDL_GetRenderDrawColor(Renderer, &old.r, &old.g, &old.g, &old.a);
//    SDL_Rect bgrect = { x, y, w, h };
//    SDL_SetRenderDrawColor(Renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
//    SDL_RenderFillRect(Renderer, &bgrect);
//    SDL_SetRenderDrawColor(Renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
//    int pw = (int)((float)w * Percent);
//    int px = x + (w - pw);
//    SDL_Rect fgrect = { px, y, pw, h };
//    SDL_RenderFillRect(Renderer, &fgrect);
//    SDL_SetRenderDrawColor(Renderer, old.r, old.g, old.b, old.a);
//}