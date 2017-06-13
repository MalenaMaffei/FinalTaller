#include "Header Files/VistaManager.h"
#include "Header Files/VistaBandera.h"
#include "Header Files/VistaRoca.h"
#include "Header Files/VistaPuente.h"
#include "Header Files/VistaFuerte.h"
#include "Header Files/VistaRobotCaminar.h"
#include "Header Files/VistaRobotMorir.h"
#include "Header Files/VistaGruntDisparar.h"
#include "Header Files/VistaLaserDisparar.h"
#include "Header Files/VistaPsychoDisparar.h"
#include "Header Files/VistaPyroDisparar.h"
#include "Header Files/VistaSniperDisparar.h"
#include "Header Files/VistaToughDisparar.h"
#include "Header Files/VistaHeavy.h"
#include "Header Files/VistaTanqueMorir.h"
#include "Header Files/VistaBala.h"
#include "Header Files/VistaFabricaVehiculo.h"
#include "Header Files/VistaFabricaRobot.h"
#define POS_CAMINAR 0
#define POS_DISPARO 1

VistaManager::VistaManager(SDL_Renderer *gRenderer) : gRenderer(gRenderer) {}

VistaDireccionada *VistaManager::getVistaDireccionada(int tipoUnidad,
                                                      int tipoVista) {
    if (!vistasDireccionadas.count(tipoUnidad)){
        fabricarVistasDeElemento(tipoUnidad);
        return vistasDireccionadas.at(tipoUnidad)[tipoVista];
    }
    return vistasDireccionadas.at(tipoUnidad)[tipoVista];
}

VistaDireccionada *VistaManager::getVistaDisparo(int tipoUnidad) {
    return getVistaDireccionada(tipoUnidad, POS_DISPARO);
}

VistaDireccionada *VistaManager::getVistaCaminar(int tipoUnidad) {
    return getVistaDireccionada(tipoUnidad, POS_CAMINAR);
}

Vista *VistaManager::getVista(int tipoElemento) {
    if (!vistas.count(tipoElemento)){
        fabricarVistasDeElemento(tipoElemento);
    }
    return vistas.at(tipoElemento);
}

void VistaManager::fabricarVistasDeElemento(int tipo) {
    if (!codigos.esUnidad(tipo)){
        Vista* vista;
        if (tipo == codigos.bandera){
            vista = new VistaBandera(gRenderer);
        } else if (tipo == codigos.roca){
            vista = new VistaRoca(gRenderer);
        } else if (tipo == codigos.puente){
            vista = new VistaPuente(gRenderer);
        } else if (tipo == codigos.fuerte){
            vista = new VistaFuerte(gRenderer);
        } else if (tipo == codigos.fabricaVehiculo){
            vista = new VistaFabricaVehiculo(gRenderer);
        } else if (tipo == codigos.fabricaRobot){
            vista = new VistaFabricaRobot(gRenderer);
        } else if (tipo == codigos.bala){
            vista = new VistaBala(gRenderer);
        }
        vistas[tipo] = vista;
    }

    if (codigos.esRobot(tipo)){
        VistaDireccionada* caminar = new VistaRobotCaminar(gRenderer);
        Vista* morir = new VistaRobotMorir(gRenderer);
        VistaDireccionada* disparar;
        if (tipo == codigos.grunt){
            disparar = new VistaGruntDisparar(gRenderer);
        } else if (tipo == codigos.laser){
            disparar = new VistaLaserDisparar(gRenderer);
        } else if (tipo == codigos.sniper){
            disparar = new VistaSniperDisparar(gRenderer);
        } else if (tipo == codigos.psycho){
            disparar = new VistaPsychoDisparar(gRenderer);
        } else if (tipo == codigos.pyro){
            disparar = new VistaPyroDisparar(gRenderer);
        } else if (tipo == codigos.tough){
            disparar = new VistaToughDisparar(gRenderer);
        }
        vistas[tipo] = morir;
        vistasDireccionadas[tipo].push_back(caminar);
        vistasDireccionadas[tipo].push_back(disparar);
    }

//    jeep = 12,
//    light = 13,
//    medium = 14,
//    heavy = 15,
//    missile = 16
    if (codigos.esTanque(tipo)){
        VistaDireccionada* caminar;
        VistaDireccionada* disparar;
        Vista* morir;
//        TODO armar aca con todas las vistas de todo el mundo
        caminar = new VistaHeavy(gRenderer);
        disparar = new VistaHeavy(gRenderer);
        morir = new VistaTanqueMorir(gRenderer);

        vistas[tipo] = morir;
        vistasDireccionadas[tipo].push_back(caminar);
        vistasDireccionadas[tipo].push_back(disparar);
    }
}
