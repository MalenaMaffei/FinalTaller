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
        printf("se encola info\n");
        paquete.pedirInfo(guiEdificio.getIdFabrica());
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
    if (clickeado->esMio()){
        paquete.pedirInfo(clickeado->getId());
        colaSalida.encolar(paquete);
        clickeado->guiRequest(*this);

    } else if (selectBox.haySeleccion()){
        vector<ElementoUnidad*> seleccion = selectBox.getSeleccionadas();
        for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad*
                                                              unidad){
              if (! unidad->estaMuriendo()){
                  paquete.atacar(unidad->getId(),clickeado->getId());
                  colaSalida.encolar(paquete);
              }
        });
    }
    click.resetCoords();
}

void ColectorDeAcciones::showEdificio(std::string id) {
    guiEdificio.abrirGui(click.getPoint(), id);
}

void ColectorDeAcciones::showHud() {
//TODO codigo para que le diga al hud que muestre otra foto
//    hud.setInfo(10);
}
