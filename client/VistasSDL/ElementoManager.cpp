#include "Header Files/ElementoManager.h"
#include "Header Files/ElementoBandera.h"
#include "Header Files/ElementoRoca.h"
#include "Header Files/ElementoPuente.h"
#include "Header Files/ElementoFuerte.h"



ElementoManager::ElementoManager(VistaManager &vistaManager) : vistaManager
                                                                   (vistaManager) {}

void ElementoManager::fabricar(Paquete &paquete) {
    if (codigos.esUnidad(paquete.getTipo())) {
        fabricarUnidad(paquete);
    } else {
        fabricarElemento(paquete);
    }

}

void ElementoManager::fabricarUnidad(Paquete &paquete) {
    Elemento* elemento;
    ElementoUnidad* unidad;
    int tipo = paquete.getTipo();
    int id = paquete.getId();
    unidad = new ElementoUnidad(id, paquete.getX(), paquete.getY(),
                                vistaManager.getVistaCaminar(tipo),
                                vistaManager.getVistaDisparo(tipo),
                                vistaManager.getVista(tipo),
                                paquete.isEsMio(), paquete.getColor());
    elemento = unidad;
    elementos[id] = elemento;
    unidades[id] = unidad;
}

void ElementoManager::fabricarElemento(Paquete &paquete) {
    Elemento *elemento;
    int tipo = paquete.getTipo();
    int id = paquete.getId();
    int x = paquete.getX();
    int y = paquete.getY();
    int color = paquete.getColor();

    if (tipo == codigos.bandera){
        elemento = new ElementoBandera(id, x, y, vistaManager.getVista(tipo),
                                       color);
    } else if (tipo == codigos.roca){
        elemento = new ElementoRoca(id, x, y, vistaManager.getVista(tipo));
    } else if (tipo == codigos.puente){
        elemento = new ElementoPuente(id, x, y, vistaManager.getVista(tipo));
    } else if (tipo == codigos.fuerte){
        elemento = new ElementoFuerte(id, x, y, vistaManager.getVista(tipo),
                                      paquete.isEsMio(), color);
    }
//        TODO faltarian los vehiculos y fabricas de robots
    elementos[id] = elemento;
}
