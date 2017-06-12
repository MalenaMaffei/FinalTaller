#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/GuiEdificio.h"
#include "Header Files/Paquete.h"
#include <algorithm>
#include <vector>
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
    if (guiEdificio.click(click.getPoint())){
        if (guiEdificio.huboSeleccion()){
            Paquete crear;
            crear.crear(guiEdificio.getFabricaId(),clicked.x,clicked.y,
                        guiEdificio.getTipoSeleccionado());
            colaSalida.encolar(crear);
            printf("paquete crear: %s\n", crear.getMensaje().c_str());
        }
        click.resetCoords();
        return;
    }

    Paquete paquete;

    if (!click.hayClickeado()){
        if (selectBox.haySeleccion()){
            vector<ElementoUnidad> seleccion=selectBox.getSeleccionadas();
            for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                                  unidad){
              if (unidad.estaMuerto()){
                  printf("unidad %i esta muerta\n", unidad.getId());
                  return;
              }
              printf("Unidad id: %i se mueve a: %i,%i\n", unidad.getId(),
                     click.getPoint().x, click.getPoint().y);
              paquete.mover(unidad.getId(), click.getPoint().x, click
                  .getPoint().y);
              colaSalida.encolar(paquete);
            });
            selectBox.vaciarSeleccionadas();
        }
        click.resetCoords();
        return;
    }

    Elemento* clickeado = click.getClicked();
    if (clickeado->esMio()){
//        printf("request info MIO de id: %s\n", clickeado->getId().c_str());
        paquete.pedirInfo(clickeado->getId());
        colaSalida.encolar(paquete);
        clickeado->guiRequest(*this);

    } else if (selectBox.haySeleccion()){
        vector<ElementoUnidad> seleccion = selectBox.getSeleccionadas();
        for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                              unidad){
              if (unidad.estaMuerto()){
                  return;
              }
            printf("Unidad id: %s ataca a Elemento id: %s",unidad.getId()
                .c_str(), clickeado->getId().c_str() );
            paquete.atacar(unidad.getId(),clickeado->getId());
            colaSalida.encolar(paquete);
        });
        selectBox.vaciarSeleccionadas();
    }
    click.resetCoords();
}

void ColectorDeAcciones::showEdificio(std::string id) {
    guiEdificio.abrirGui(click.getPoint(), id);
}

void ColectorDeAcciones::showHud() {
//TODO codigo para que le diga al hud que muestre otra foto
    hud.setInfo(0);
}
