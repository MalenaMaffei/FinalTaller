#include "Header Files/FabricaElemento.h"
#include "Header Files/ElementoBandera.h"
#include "Header Files/ElementoRoca.h"
#include "Header Files/ElementoPuente.h"
#include "Header Files/ElementoFuerte.h"

#define POS_CAMINAR 0
#define POS_DISPARO 1

FabricaElemento::FabricaElemento(std::map<int, Vista *> &vistas,
                             std::map<int,
                                      std::vector<VistaDireccionada *>> vistasDireccionadas,
                             std::map<int, Elemento *> &elementos,
                             std::map<int, ElementoUnidad *> &unidades)
    : vistas(vistas),
      vistasDireccionadas(vistasDireccionadas),
      elementos(elementos),
      unidades(unidades) {
}

void FabricaElemento::fabricar(Paquete &paquete) {
    if (codigos.esUnidad(paquete.getTipo())) {
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

    if (tipo == codigos.bandera){
        elemento = new ElementoBandera(id, x, y, vistas.at(tipo), color);
    } else if (tipo == codigos.roca){
        elemento = new ElementoRoca(id, x, y, vistas.at(tipo));
    } else if (tipo == codigos.puente){
        elemento = new ElementoPuente(id, x, y, vistas.at(tipo));
    } else if (tipo == codigos.fuerte){
        elemento = new ElementoFuerte(id, x, y, vistas.at(tipo), false, color);
    }
//        TODO faltarian los vehiculos y fabricas de robots
    elementos[id] = elemento;
}
