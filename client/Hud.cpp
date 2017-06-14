#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#include "Header Files/VistaHudVehiculoLabels.h"
#include "Header Files/VistaHudRobotLabels.h"
#include "Header Files/common_CodigosPaquete.h"
#define X_CARA 8
#define Y_CARA 46
#define X_LABEL_ROBOT 2
#define Y_LABEL_ROBOT 124
#define X_HPBAR 14
#define Y_HPBAR 210
#define HEIGHT_HPBAR 14
#define WIDTH_HPBAR 76
Hud::Hud(SDL_Renderer *gRenderer,
         Vista &hud,
         Vista &vistaCaras,
         Vista &labelsRobot,
         Vista &labelsVehiculo,
         VistaProgressBar &barraVida) : vistaHud(hud), vistaCaras
    (vistaCaras),
//                                  barraVida({Punto(X_HPBAR, Y_HPBAR), WIDTH_HPBAR,HEIGHT_HPBAR},
//    gRenderer, {60,175,23}, {99,71,71}),
                                        barraVida(barraVida),
                                  seleccionado(false),
                                        ubicacion(SCREEN_WIDTH - hud.getWidth(), 0), labelsRobot(labelsRobot),
                                        labelsVehiculo(labelsVehiculo){
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
        vistaCaras.mostrar(caraPos, getPosLabel());
        Punto labelRobotOffset(X_LABEL_ROBOT, Y_LABEL_ROBOT);
        Punto labelRobotPos = ubicacion + labelRobotOffset;
        labelsRobot.mostrar(labelRobotPos, getPosLabel());
        barraVida.llenarHorizontal(vida, Punto(X_HPBAR, Y_HPBAR)+ubicacion);
    }
}

//TODO TANQUE SI ESTA CON ALGUIEN ES SIEMPRE UN GRUNT!!!

//TODO todos los turnos pido info del id seleccionado
//TODO en realidad me va a llegar un paquete y el me dira que hacer
void Hud::setInfo(int tipo, int porcentajeVida) {
    tipoCara = tipo;
    float cienporciento = 100;
    vida = porcentajeVida/cienporciento;
    seleccionado = true;
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
//    TODO usar un mapa
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

