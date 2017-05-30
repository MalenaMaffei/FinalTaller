#include "FabricaElemento.h"
#include "ElementoBandera.h"
#include "ElementoRoca.h"
#include "ElementoPuente.h"
#include "ElementoFuerte.h"
#define POS_CAMINAR 0
#define POS_DISPARO 1
#define COMIENZO_UNIDADES 6
FabricaElemento::FabricaElemento(std::map<int, Vista *> &vistas,
                             std::map<int,
                                      std::vector<VistaDireccionada *>> vistasDireccionadas,
                             std::map<int, Elemento *> &elementos,
                             std::map<int, ElementoUnidad *> &unidades)
    : vistas(vistas),
      vistasDireccionadas(vistasDireccionadas),
      elementos(elementos),
      unidades(unidades) {}

void FabricaElemento::fabricar(Paquete &paquete) {
    if (paquete.getTipo() >= 6) {
        fabricarUnidad(paquete);
    } else {
        fabricarElemento(paquete);
    }

}

void FabricaElemento::fabricarUnidad(Paquete &paquete) {
    Elemento* elemento;
    ElementoUnidad* unidad;
    int tipo = paquete.getTipo();
    int id = paquete.getId();
    unidad = new ElementoUnidad(id, paquete.getX(), paquete.getY(),
                                vistasDireccionadas.at
                                    (tipo)[POS_CAMINAR], vistasDireccionadas.at
            (tipo)[POS_DISPARO], vistas.at(tipo), paquete.isEsMio(), paquete.getColor
            ());
    elemento = unidad;
    elementos[id] = elemento;
    unidades[id] = unidad;
}

void FabricaElemento::fabricarElemento(Paquete &paquete) {
    Elemento *elemento;
    int tipo = paquete.getTipo();
    int id = paquete.getId();
    int x = paquete.getX();
    int y = paquete.getY();
    int color = paquete.getColor();

    switch (tipo) {
        case bandera: {
            elemento = new ElementoBandera(id, x, y, vistas.at(tipo), color);
        } break;

        case roca: {
            elemento = new ElementoRoca(id, x, y, vistas.at(tipo));
        } break;

        case puente: {
            elemento = new ElementoPuente(id, x, y, vistas.at(tipo));
        } break;

        case fuerte: {
            elemento = new ElementoFuerte(id, x, y, vistas.at(tipo), color);
        }
//        TODO faltarian los vehiculos y fabricas de robots
    }
}
