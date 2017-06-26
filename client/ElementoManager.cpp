#include <algorithm>
#include "Header Files/ElementoManager.h"
#include "Header Files/ElementoBandera.h"
#include "Header Files/ElementoRoca.h"
#include "Header Files/ElementoPuente.h"
#include "Header Files/ElementoEstructura.h"
#include "Header Files/Mouse.h"
#include "Header Files/PaqueteAccion.h"
#include <vector>
#include <string>
using std::string;
ElementoManager::ElementoManager(VistaManager &vistaManager,
                                 int MiColor) :
    vistaManager(vistaManager), miColor(MiColor) {}

void ElementoManager::crear(PaqueteAccion &paquete) {
    if (codigos.esUnidad(paquete.getTipo())) {
        fabricarUnidad(paquete);
    } else {
        fabricarElemento(paquete);
    }
}

void ElementoManager::fabricarUnidad(PaqueteAccion &paquete) {
    ElementoUnidad* unidad;
    int tipo = paquete.getTipo();
    string id = paquete.getId();
    Punto pos = {paquete.getX(), paquete.getY()};
    unidad = new ElementoUnidad(id,pos,
                                vistaManager.getVistaCaminar(tipo),
                                vistaManager.getVistaDisparo(tipo),
                                vistaManager.getVista(tipo),
                                paquete.getColor() == miColor,
                                paquete.getColor());

    unidades[id] = unidad;
}

void ElementoManager::fabricarElemento(PaqueteAccion &paquete) {
    Elemento *elemento;
    int tipo = paquete.getTipo();
    string id = paquete.getId();
    Punto pos = {paquete.getX(), paquete.getY()};
    int color = paquete.getColor();

    if (tipo == codigos.bandera){
        elemento =
            new ElementoBandera(id, pos, vistaManager.getVista(tipo), color);
    } else if (tipo == codigos.roca){
        elemento = new ElementoRoca(id, pos, vistaManager.getVista(tipo));
    } else if (tipo == codigos.puente){
        elemento =
            new ElementoPuente(id, pos, vistaManager.getVista(tipo), false);
    } else if (tipo == codigos.fuerte){
        elemento = new ElementoEstructura(id, pos,vistaManager.getVista(tipo),
                                          color == miColor, color);
    } else if (tipo == codigos.fabricaVehiculo){
        elemento = new ElementoEstructura(id, pos, vistaManager.getVista(tipo),
                                          color == miColor, color);
    } else if (tipo == codigos.fabricaRobot){
        elemento = new ElementoEstructura(id, pos, vistaManager.getVista(tipo),
                                          color == miColor, color);
    } else if (codigos.esBala(tipo)){
        ElementoBala* bala;
        bala = new ElementoBala(id, pos, vistaManager.getVista(codigos.bala));
        balas[id] = bala;
        return;
    }
    elementos[id] = elemento;
}

void ElementoManager::elementosVivir(Camara &camara,Click &click,
                                     SelectBox &selectBox) {
//    TODO remove_if remove_copy_if, ver si estos no son mejores.
    std::vector<string> muertos;
    for (const auto& kv : elementos) {
        Elemento* elemento = elementos.at(kv.first);
        if (elemento->estaMuerto()){
            muertos.push_back(elemento->getId());
        } else {
            elemento->mostrar(camara);
            elemento->clicked(click);
        }
    }

    for (const auto& kv : balas) {
        Elemento* elemento = balas.at(kv.first);
        if (elemento->estaMuerto()){
            muertos.push_back(elemento->getId());
        } else {
            elemento->mostrar(camara);
        }
    }

    for (const auto& kv : unidades) {
        ElementoUnidad* unidad = unidades.at(kv.first);
        if (unidad->estaMuerto()){
            muertos.push_back(unidad->getId());
        } else {
            unidad->mostrar(camara);
            unidad->clicked(click);
            unidad->chequearSeleccion(selectBox);
        }
    }

    limpiarMuertos(muertos);
}

void ElementoManager::matar(PaqueteAccion &paquete) {
    Elemento* elemento;
    std::string id = paquete.getId();
    if (elementos.count(id)){
        elemento = elementos.at(id);
    } else if (unidades.count(id)){
        elemento = unidades.at(id);
    }else if (balas.count(id)){
        elemento = balas.at(id);
    }
    elemento->matar();
}

void ElementoManager::limpiarMuertos(std::vector<string> &muertos) {
    if (muertos.empty()){
        return;
    }
    std::for_each(muertos.begin(), muertos.end(), [&](string id){
      Elemento* elemento;
      if (elementos.count(id)){
          elemento = elementos.at(id);
          elementos.erase(id);
      } else if (unidades.count(id)){
          elemento = unidades.at(id);
          unidades.erase(id);
      } else if (balas.count(id)){
          elemento = balas.at(id);
          balas.erase(id);
      }
      delete elemento;
    });
}

void ElementoManager::mover(PaqueteAccion &paquete) {
    string id = paquete.getId();
    Punto destino = Punto(paquete.getX(), paquete.getY());
    if (unidades.count(id)){
        ElementoUnidad* unidad = unidades.at(id);
        unidad->mover(destino);
    } else if (balas.count(id)){
        ElementoBala* bala = balas.at(id);
        bala->mover(destino);
    }
}

void ElementoManager::disparar(PaqueteAccion &paquete) {
    ElementoUnidad* unidad = unidades.at(paquete.getId());
    unidad->disparar(Punto(paquete.getX(), paquete.getY()));
}

ElementoManager::~ElementoManager() {
    printf("borrando elementos\n");
    for (const auto& kv : elementos) {
        delete kv.second;
    }

    for (const auto& kv : unidades) {
        delete kv.second;
    }

    for (const auto& kv : balas) {
        delete kv.second;
    }
}
