#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#include "Header Files/VistaLabelVehiculo.h"
#include "Header Files/VistaLabelRobot.h"
#include "Header Files/common_CodigosPaquete.h"
#include "Header Files/PaqueteAccion.h"
#include "LabelRobot.h"
#include "Header Files/VistaIconoRobot.h"
#include "Header Files/VistaHud.h"
#include "LabelVehiculo.h"
#include "IconoRobot.h"
#include "IconoVehiculo.h"
#include "IconoArma.h"
#include "Header Files/PaqueteUnidad.h"
#define X_HPBAR 14
#define Y_HPBAR 213
#define HEIGHT_HPBAR 7
#define WIDTH_HPBAR 73
#include <string>
#include <algorithm>
Hud::Hud(SDL_Renderer *gRenderer) : vistaHud(VistaHud(gRenderer)),
                                    barraVida(gRenderer,
                                              {60, 175, 23},
                                              {99, 71, 71},
                                              Rect(Punto(X_HPBAR, Y_HPBAR),
                                              WIDTH_HPBAR, HEIGHT_HPBAR))
    , seleccionado(false), ubicacion(SCREEN_WIDTH - vistaHud.getWidth(), 0) {
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
        barraVida.mostrar(ubicacion);
    }
}

void Hud::setInfo(Paquete paquete) {
    CodigosPaquete codigos;
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    barraVida.setInfo(paqueteUnidad.getVida());
    seleccionado = true;
//    TODO paqueteUnidad
    PaqueteAccion nuevo;
    std::string nuevoMensaje =  paquete.getMensaje() + std::to_string(color);
    nuevo.setMensaje(nuevoMensaje);
    std::for_each(elementos.begin(), elementos.end(),[&](ElementoGui* ele){
      ele->setInfo(nuevo);
    });
}

bool Hud::click(Punto click) {
//    TODO hud rect nunca seleccionado
    bool huboClick = hudRect.incluyePunto(click);
    printf("click %i,%i, hudRect: %i,%i\n", click.x, click.y, hudRect.x,
           hudRect.y);
    seleccionado = huboClick;
    esperandoInfo  = huboClick;
    return huboClick;
}

Hud::~Hud() {
    printf("se va a borar hud\n");
    std::for_each(elementos.begin(), elementos.end(), [&](ElementoGui* ele){
      delete ele;
    });
}

void Hud::abrirGui(std::string id, int color) {
    Hud::color = color;
    esperandoInfo = true;
    idSeleccionado = id;
}

bool Hud::activo() {
    return esperandoInfo;
}

const std::string &Hud::getIdSeleccionado() const {
    return idSeleccionado;
}
