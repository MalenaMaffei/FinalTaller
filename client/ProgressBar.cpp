#include <SDL_render.h>
#include "Header Files/ProgressBar.h"

ProgressBar::ProgressBar(SDL_Renderer *gRenderer,
                         const SDL_Color &FGColor,
                         const SDL_Color &BGColor,
                         Rect barra,
                         bool vertical)
    : barra(barra),gRenderer(gRenderer), FGColor(FGColor),
    BGColor(BGColor), vertical(vertical), porcentaje(0) {}

void ProgressBar::dibujarRect(Rect rect, SDL_Color color) {
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 0);
    SDL_RenderFillRect(gRenderer, &rect);
}

void ProgressBar::llenarBarra(Punto offset, Rect porcentajeRect) {
    Rect backgroundRect = barra.positiveShift(offset);
    dibujarRect(backgroundRect, BGColor);
    dibujarRect(porcentajeRect, FGColor);
}

void ProgressBar::mostrarHorizontal(Punto offset) {
    int pw = barra.w * porcentaje;
    Rect porcentajeRect = barra.positiveShift(offset);
    porcentajeRect.w = pw;
    llenarBarra(offset, porcentajeRect);
}

void ProgressBar::mostrarVertical(Punto offset) {
    int ph = barra.h * porcentaje;
    Rect porcentajeRect = barra.positiveShift(offset + Punto(0, barra.h - ph));
    porcentajeRect.h = ph;
    llenarBarra(offset, porcentajeRect);
}

void ProgressBar::mostrar(Punto offset) {
    if (vertical){
        mostrarVertical(offset);
    } else {
        mostrarHorizontal(offset);
    }
}

void ProgressBar::setInfo(float porcentaje) {
    ProgressBar::porcentaje = porcentaje;
}

