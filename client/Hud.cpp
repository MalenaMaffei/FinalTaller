#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#include "Header Files/VistaLabelVehiculo.h"
#include "Header Files/VistaLabelRobot.h"
#include "Header Files/common_CodigosPaquete.h"
#include "Header Files/Paquete.h"
#include "LabelRobot.h"
#include "Header Files/VistaIconoRobot.h"
#include "Header Files/VistaHud.h"
#include "LabelVehiculo.h"
#include "IconoRobot.h"
#include "IconoVehiculo.h"
#include "IconoArma.h"
#define X_HPBAR 14
#define Y_HPBAR 213
#define HEIGHT_HPBAR 7
#define WIDTH_HPBAR 73

#include <algorithm>
Hud::Hud(SDL_Renderer *gRenderer) : vistaHud(VistaHud(gRenderer)),
    barraVida(76, 8, gRenderer,{60, 175,23},{99, 71, 71}),seleccionado(false),
    ubicacion(SCREEN_WIDTH - vistaHud.getWidth(), 0) {
    hudRect = {ubicacion,vistaHud.getWidth(),vistaHud.getHeight()};

    ElementoGui* elementoGui = new LabelRobot(gRenderer);
    elementos.push_back(elementoGui);
    elementoGui = new LabelVehiculo(gRenderer);
    elementos.push_back(elementoGui);
    elementoGui = new IconoRobot(gRenderer);
    elementos.push_back(elementoGui);
    elementoGui = new IconoVehiculo(gRenderer);
    elementos.push_back(elementoGui);
    elementoGui = new IconoArma(gRenderer);
    elementos.push_back(elementoGui);
}

void Hud::mostrar() {
    if (seleccionado){
        vistaHud.mostrar(ubicacion, 0);
        std::for_each(elementos.begin(), elementos.end(),[&](ElementoGui* ele){
          ele->mostrar(ubicacion);
        });
        barraVida.mostrarHorizontal(vida, Punto(X_HPBAR, Y_HPBAR) + ubicacion);
    }
}

void Hud::setInfo(Paquete paquete) {
    CodigosPaquete codigos;
    int porcentajeVida = std::stoi(paquete.getMensaje().substr(6,3));
    float cienporciento = 100;
    vida = porcentajeVida/cienporciento;
    seleccionado = true;

    std::for_each(elementos.begin(), elementos.end(),[&](ElementoGui* ele){
      ele->setInfo(paquete);
    });
}
