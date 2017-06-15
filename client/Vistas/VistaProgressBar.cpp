#include <SDL_render.h>
#include "../Header Files/VistaProgressBar.h"

VistaProgressBar::VistaProgressBar(int width,
                                   int height,
                                   SDL_Renderer *gRenderer,
                                   const SDL_Color &FGColor,
                                   const SDL_Color &BGColor)
    : width(width), height(height),gRenderer(gRenderer), FGColor(FGColor),
    BGColor(BGColor) {}

void VistaProgressBar::dibujarRect(Rect rect, SDL_Color color) {
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 0);
    SDL_RenderFillRect(gRenderer, &rect);
}

void VistaProgressBar::llenarBarra(Punto ubicacion, Rect porcentajeRect) {
    Rect backgroundRect = {ubicacion, width, height};
    dibujarRect(backgroundRect, BGColor);
    dibujarRect(porcentajeRect, FGColor);
}

void VistaProgressBar::mostrarHorizontal(float porcentaje, Punto ubicacion) {
    int pw = width * porcentaje;
    Rect porcentajeRect = {ubicacion, pw, height};
    llenarBarra(ubicacion, porcentajeRect);
}

void VistaProgressBar::mostrarVertical(float porcentaje, Punto ubicacion) {
    int ph = height * porcentaje;
    Punto porcentajeStart = ubicacion + Punto(0, height - ph);
    Rect porcentajeRect = { porcentajeStart, width, ph };
    llenarBarra(ubicacion, porcentajeRect);
}

