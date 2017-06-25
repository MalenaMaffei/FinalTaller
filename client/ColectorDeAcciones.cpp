#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/GuiEdificio.h"
#include "Header Files/Paquete.h"
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
    if (!click.huboClick()){
        return;
    }

    Punto clicked = click.getPoint();
    Paquete paquete;
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
              if (!unidad->estaMuerto()){
                  printf("por encolar mover.");
                  paquete.mover(unidad->getId(), clicked.x, clicked.y);
                  colaSalida.encolar(paquete);
                  printf("se encolo mover\n");
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
              if (! unidad->estaMuerto()){
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
