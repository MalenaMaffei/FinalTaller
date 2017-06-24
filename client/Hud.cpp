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
//                                    vistaCaras
//    (VistaIconoRobot(gRenderer)),
    barraVida(76, 8, gRenderer,{60, 175,23},{99, 71, 71}),
                                    seleccionado(false),
    ubicacion(SCREEN_WIDTH - vistaHud.getWidth(), 0)
//    ,
//                                    labelsRobot(labelsRobot),
//    labelsVehiculo(labelsVehiculo)
{
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
    vistaHud.mostrar(ubicacion, 0);
    mostrarContenido();
//    TODO sacar despues
    if (seleccionado){
//        TODO hacer esto atributo
//        Punto caraOffset(X_CARA,Y_CARA);
//        Punto caraPos = ubicacion + caraOffset;
//        vistaCaras.mostrar(caraPos, getPosLabel());

        std::for_each(elementos.begin(), elementos.end(),[&](ElementoGui* ele){
          ele->mostrar(ubicacion);
        });
//        Punto labelRobotOffset(X_LABEL_ROBOT, Y_LABEL_ROBOT);
//        Punto labelRobotPos = ubicacion + labelRobotOffset;
//        labelsRobot.mostrar(labelRobotPos, getPosLabel());

        barraVida.mostrarHorizontal(vida, Punto(X_HPBAR, Y_HPBAR) + ubicacion);
    }
}


void Hud::setInfo(Paquete paquete) {
    CodigosPaquete codigos;
//    int tipo = std::stoi(paquete.getMensaje().substr(4,codigos.tipo));
    int porcentajeVida = std::stoi(paquete.getMensaje().substr(6,3));
//    tipoCara = tipo;
    float cienporciento = 100;
    vida = porcentajeVida/cienporciento;
    seleccionado = true;

    std::for_each(elementos.begin(), elementos.end(),[&](ElementoGui* ele){
      ele->setInfo(paquete);
    });


}

void Hud::mostrarContenido() {
//    TODO IF CARA IF ESTO IF LO OTRO
}

int Hud::getPosLabel() {
    CodigosPaquete codigos;
    if (!codigos.esRobot(tipoCara)){
//        TODO todavia no se muestran otras cosas que no sean robots
        return 0;
    }
//    TODO usar un mapa o pasar esto a VistaCaras
    if (tipoCara == codigos.grunt){
        return labelGrunt;
    } else if (tipoCara == codigos.laser){
        return labelLaser;
    } else if (tipoCara == codigos.pyro){
        return labelPyros;
    } else if (tipoCara == codigos.psycho){
        return labelPsychos;
    } else if (tipoCara == codigos.sniper){
        return labelSniper;
    } else if (tipoCara == codigos.tough){
        return labelTough;
    }
}
