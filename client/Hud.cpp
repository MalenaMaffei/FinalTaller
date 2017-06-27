#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#include "Header Files/VistaLabelVehiculo.h"
#include "Header Files/VistaLabelRobot.h"
#include "Header Files/CodigosPaquete.h"
#include "Header Files/VistaIconoRobot.h"
#include "Header Files/VistaHud.h"
#include "Header Files/RobotGallery.h"
#include "Header Files/VehiculoGallery.h"
#include "Header Files/ArmaGallery.h"
#include "Header Files/PaqueteUnidad.h"
#include "Header Files/Click.h"
#include "Header Files/VistaIconoVehiculo.h"
#include "Header Files/VistaIconoArma.h"
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
    , seleccionado(false), ubicacion(SCREEN_WIDTH - vistaHud.getWidth(), 0),
                                    esperandoInfo(false) {
    hudRect = {ubicacion,vistaHud.getWidth(),vistaHud.getHeight()};

    GuiGallery* elementoGui = new RobotGallery(new VistaLabelRobot(gRenderer),
                                               {3,124});
    elementos.push_back(elementoGui);
    elementoGui = new VehiculoGallery(new VistaLabelVehiculo(gRenderer),
                                      {2, 230});
    elementos.push_back(elementoGui);
    elementoGui = new RobotGallery(new VistaIconoRobot(gRenderer), {8, 46});
    elementos.push_back(elementoGui);
    elementoGui = new VehiculoGallery(new VistaIconoVehiculo(gRenderer),
                                      {0, 148});
    elementos.push_back(elementoGui);
    elementoGui = new ArmaGallery(new VistaIconoArma(gRenderer), {0,144});
    elementos.push_back(elementoGui);
}

void Hud::mostrar() {
    if (seleccionado){
        vistaHud.mostrar(ubicacion, 0);
        std::for_each(elementos.begin(), elementos.end(),[&](GuiGallery* ele){
          ele->mostrar(ubicacion);
        });
        barraVida.mostrar(ubicacion);
    }
}

void Hud::setInfo(PaqueteUnidad paquete) {
    if (!esperandoInfo){
        return;
    }
    CodigosPaquete codigos;
    PaqueteUnidad paqueteUnidad(paquete.getMensaje());
    barraVida.setInfo(paqueteUnidad.getVida());
    seleccionado = true;
    std::string nuevoMensaje =  paquete.getMensaje() + std::to_string(color);
    PaqueteUnidad nuevo(nuevoMensaje);

//    Se le pasa el paquete con información de la unidad a cada elemento para
// que se setee y muestre lo que debe.
    std::for_each(elementos.begin(), elementos.end(),[&](GuiGallery* ele){
      ele->setInfo(nuevo);
    });
}

bool Hud::click(Click click) {
    if (seleccionado){
//        Si se hizo click sobre el HUD, lo cierro
        Punto p = click.getScreenCoords();
        bool huboClick = hudRect.incluyePunto(p);
        seleccionado = !huboClick;
        esperandoInfo  = !huboClick;
        return huboClick;
    }
    return false;
}

Hud::~Hud() {
    std::for_each(elementos.begin(), elementos.end(), [&](GuiGallery* ele){
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
