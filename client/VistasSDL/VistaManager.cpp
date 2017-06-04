#include "VistaManager.h"
#define POS_CAMINAR 0
#define POS_DISPARO 1

VistaManager::VistaManager(){}

VistaDireccionada *VistaManager::getVistaDireccionada(int tipoUnidad,
                                                      int tipoVista) {
    if(! vistasDireccionadas.count(tipoUnidad)){
        fabricarVistasDeElemento(tipoUnidad);
        return vistasDireccionadas.at(tipoUnidad)[tipoVista];
    }
}

VistaDireccionada *VistaManager::getVistaDisparo(int tipoUnidad) {
    return getVistaDireccionada(tipoUnidad, POS_DISPARO);
}

VistaDireccionada *VistaManager::getVistaCaminar(int tipoUnidad) {
    return getVistaDireccionada(tipoUnidad, POS_CAMINAR);
}

//TODO este metodo es necesario?
//Vista *VistaManager::getVistaMuerte(int tipoUnidad) {
//    return nullptr;
//}

Vista *VistaManager::getVista(int tipoElemento) {
    if(! vistas.count(tipoElemento)){
        fabricarVistasDeElemento(tipoElemento);
        return vistas.at(tipoElemento);
    }
}

void VistaManager::fabricarVistasDeElemento(int tipo) {

}

