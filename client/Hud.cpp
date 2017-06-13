#include "Header Files/Hud.h"
#include "Header Files/constantes.h"
#include "Header Files/VistaHudVehiculoLabels.h"
#include "Header Files/VistaHudRobotLabels.h"
#include "Header Files/common_CodigosPaquete.h"
#define X_CARA 8
#define Y_CARA 46
#define X_LABEL_ROBOT 2
#define Y_LABEL_ROBOT 124
Hud::Hud(SDL_Renderer *gRenderer,
         Vista &hud,
         Vista &vistaCaras,
         Vista &labelsRobot,
         Vista &labelsVehiculo) : vistaHud(hud), vistaCaras
    (vistaCaras), seleccionado(false),
                                  ubicacion(SCREEN_WIDTH - hud.getWidth(), 0),
                                  labelsRobot(labelsRobot), labelsVehiculo
                                          (labelsVehiculo){
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
        printf("pos label : %i\n", getPosLabel());
        vistaCaras.mostrar(caraPos, getPosLabel());
        Punto labelRobotOffset(X_LABEL_ROBOT, Y_LABEL_ROBOT);
        Punto labelRobotPos = ubicacion + labelRobotOffset;
        labelsRobot.mostrar(labelRobotPos, getPosLabel());
    }
}

//TODO TANQUE SI ESTA CON ALGUIEN ES SIEMPRE UN GRUNT!!!

//TODO todos los turnos pido info del id seleccionado
//TODO en realidad me va a llegar un paquete y el me dira que hacer
void Hud::setInfo(int tipo) {
    tipoCara = tipo;
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
