#include <SDL_render.h>
#include "../Header Files/VistaProgressBar.h"

VistaProgressBar::VistaProgressBar(int width,
                                   int height,
                                   SDL_Renderer *gRenderer,
                                   const SDL_Color &FGColor,
                                   const SDL_Color &BGColor)
    : width(width), height(height),gRenderer(gRenderer), FGColor(FGColor),
BGColor
    (BGColor) {}

void VistaProgressBar::llenarHorizontal(float porcentaje, Punto ubicacion) {
//    porcentaje = porcentaje > 1.f ? 1.f : porcentaje < 0.f ? 0.f : porcentaje;

//    TODO usar dos texturas, la del fondo y la verde... aunque en ese caso
// deberia hacer distintas vistas para las distintas barras, no se si vale la
// pena
//    TODO darle un borde al rectangulo
    Rect renderRect = {ubicacion, width, height};
    SDL_Color old;
    SDL_GetRenderDrawColor(gRenderer, &old.r, &old.g, &old.g, &old.a);
    SDL_SetRenderDrawColor(gRenderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
    SDL_RenderFillRect(gRenderer, &renderRect);
    SDL_SetRenderDrawColor(gRenderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
    int pw = width * porcentaje;
    SDL_Rect porcentajeRect = { renderRect.x, renderRect.y, pw, height };
    SDL_RenderFillRect(gRenderer, &porcentajeRect);
    SDL_SetRenderDrawColor(gRenderer, old.r, old.g, old.b, old.a);
}


/*

   Render a Vertical Percentage Bar
   Drains top to bottom normally, if height is negative it will drain bottom to top
   Percent is clamped 0.0f - 1.0f

*/

//void RenderVPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor) {
//    Percent = Percent > 1.f ? 1.f : Percent < 0.f ? 0.f : Percent;
//    SDL_Color old;
//    SDL_GetRenderDrawColor(Renderer, &old.r, &old.g, &old.g, &old.a);
//    SDL_Rect bgrect = { x, y, w, h };
//    SDL_SetRenderDrawColor(Renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
//    SDL_RenderFillRect(Renderer, &bgrect);
//    SDL_SetRenderDrawColor(Renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
//    int ph = (int)((float)h * Percent);
//    int py = y + (h - ph);
//    SDL_Rect fgrect = { x, py, w, ph };
//    SDL_RenderFillRect(Renderer, &fgrect);
//    SDL_SetRenderDrawColor(Renderer, old.r, old.g, old.b, old.a);
//}

