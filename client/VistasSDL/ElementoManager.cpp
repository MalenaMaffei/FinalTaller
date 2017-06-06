#include <algorithm>
#include "Header Files/ElementoManager.h"
#include "Header Files/ElementoBandera.h"
#include "Header Files/ElementoRoca.h"
#include "Header Files/ElementoPuente.h"
#include "Header Files/ElementoFuerte.h"
#include "Header Files/Mouse.h"

ElementoManager::ElementoManager(VistaManager &vistaManager) :
    vistaManager(vistaManager) {}

void ElementoManager::fabricar(PaqueteEntrada &paquete) {
    if (codigos.esUnidad(paquete.getTipo())) {
        fabricarUnidad(paquete);
    } else {
        fabricarElemento(paquete);
    }
}

void ElementoManager::fabricarUnidad(PaqueteEntrada &paquete) {
//    TODO mejor tengo unidades por un lado y elementos x el otro?
    ElementoUnidad* unidad;
    int tipo = paquete.getTipo();
    int id = paquete.getId();
    unidad = new ElementoUnidad(id, paquete.getX(), paquete.getY(),
                                vistaManager.getVistaCaminar(tipo),
                                vistaManager.getVistaDisparo(tipo),
                                vistaManager.getVista(tipo),
                                paquete.isEsMio(), paquete.getColor());

    unidades[id] = unidad;
    printf("creo en %i,%i\n", paquete.getX(), paquete.getY());
}

void ElementoManager::fabricarElemento(PaqueteEntrada &paquete) {
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

void ElementoManager::elementosVivir(Camara &camara,Click &click,
                                     SelectBox &selectBox) {
    std::vector<int> muertos;
    for (const auto& kv : elementos) {
        Elemento* elemento = elementos.at(kv.first);
        if (elemento->estaMuerto()){
            muertos.push_back(elemento->getId());
        } else {
            elemento->mostrar(camara);
            elemento->clicked(click);
        }
    }

    for (const auto& kv : unidades) {
        ElementoUnidad* unidad = unidades.at(kv.first);
        if (unidad->estaMuerto()){
            muertos.push_back(unidad->getId());
        } else {
            unidad->mostrar(camara);
            unidad->chequearSeleccion(selectBox);
            unidad->clicked(click);
        }
    }

    limpiarMuertos(muertos);
}

void ElementoManager::matar(PaqueteEntrada &paquete) {
    Elemento* elemento;
    int id = paquete.getId();
    if (elementos.count(id)){
        elemento = elementos.at(id);
    } else if (unidades.count(id)){
        elemento = unidades.at(id);
    }
    elemento->matar();
}

void ElementoManager::limpiarMuertos(std::vector<int> &muertos) {
    std::for_each(muertos.begin(), muertos.end(), [&](int id){
        Elemento* elemento;
        if (elementos.count(id)){
            elemento = elementos.at(id);
            elementos.erase(id);
            delete(elemento);
        }  else if (unidades.count(id)){
            elemento = unidades.at(id);
            unidades.erase(id);
            delete(elemento);
        }
    });
}

void ElementoManager::mover(PaqueteEntrada &paquete) {
    ElementoUnidad* unidad = unidades.at(paquete.getId());
    unidad->mover(Punto());
}

void ElementoManager::disparar(PaqueteEntrada &paquete) {
//    TODO terminar disparar
//    ElementoUnidad* unidad = unidades.at(paquete.getId());

}
