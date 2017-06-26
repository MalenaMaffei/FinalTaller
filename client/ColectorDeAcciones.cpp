#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/GuiEdificio.h"
#include "Header Files/PaqueteAccion.h"
#include "Header Files/ColaPaquetes.h"
#include <algorithm>
#include <vector>
#include <string>
using std::vector;
using std::for_each;

ColectorDeAcciones::ColectorDeAcciones(SelectBox &selectBox,
                                       Click &click,
                                       Hud &hud,
                                       GuiEdificio &guiEdificio,
                                       ColaPaquetes &salida)
    : selectBox(selectBox), click(click), guiEdificio(guiEdificio), hud(hud),
      colaSalida(salida){}

void ColectorDeAcciones::crearAcciones() {
    if (guiEdificio.activo()){
        PaqueteAccion paquete;
        paquete.pedirInfo(guiEdificio.getIdFabrica());
        colaSalida.encolar(paquete);
    }
    if (hud.activo()){
        PaqueteAccion paquete;
        paquete.pedirInfo(hud.getIdSeleccionado());
        colaSalida.encolar(paquete);
    }

    if (!click.huboClick()){
        return;
    }

    Punto clicked = click.getPoint();
    PaqueteAccion paquete;
//    TODO refactor esto
    if (guiEdificio.click(clicked)){
        if (guiEdificio.huboSeleccion()){
            paquete.crear(guiEdificio.getIdFabrica(),
                        guiEdificio.getTipoSeleccionado());
            colaSalida.encolar(paquete);
        }
        click.resetCoords();
        return;
    } else if (hud.click(clicked)){
        click.resetCoords();
        return;
    }

    if (!click.hayClickeado()){
        if (selectBox.haySeleccion()){
            vector<ElementoUnidad*> seleccion=selectBox.getSeleccionadas();
            for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad*
                                                                  unidad){
              if (!unidad->estaMuriendo()){
                  paquete.mover(unidad->getId(), clicked.x, clicked.y);
                  colaSalida.encolar(paquete);
              }
            });
        }
        click.resetCoords();
        return;
    }

    Elemento* clickeado = click.getClicked();
    if (selectBox.haySeleccion() && !clickeado->esMio()){
        vector<ElementoUnidad*> seleccion = selectBox.getSeleccionadas();
        for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad*
                                                              unidad){
              if (!unidad->estaMuriendo()){
                  paquete.atacar(unidad->getId(),clickeado->getId());
                  colaSalida.encolar(paquete);
              }
        });
    } else {
        clickeado->guiRequest(*this);
    }
    
    click.resetCoords();
}

void ColectorDeAcciones::showEdificio(std::string id) {
    PaqueteAccion p;
    p.pedirInfo(id);
    colaSalida.encolar(p);
    guiEdificio.abrirGui(click.getPoint(), id);
}

void ColectorDeAcciones::showHud(std::string id, int color) {
    PaqueteAccion p;
    p.pedirInfo(id);
    colaSalida.encolar(p);
    hud.abrirGui(id, color);
}
