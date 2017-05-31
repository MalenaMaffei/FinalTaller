#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/GuiEdificio.h"
#include <algorithm>
#include <vector>
ColectorDeAcciones::ColectorDeAcciones(SelectBox &selectBox,
                                       Click &click,
                                       Hud &hud,
                                       GuiEdificio &guiEdificio)
    : selectBox(selectBox), click(click), guiEdificio(guiEdificio), hud(hud) {}

void ColectorDeAcciones::crearAcciones() {
    if (!click.huboClick()){
        return;
    }

//    TODO llevarme de aca el paquete que tenga que mandar al servidor
    if (guiEdificio.click(click.getPoint())){
        click.resetCoords();
        return;
    }



    if (!click.hayClickeado()){
        if (selectBox.haySeleccion()){
            std::vector<ElementoUnidad> seleccion = selectBox.getSeleccionadas();
            std::for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                                  unidad){
              printf("Unidad id: %i se mueve a: %i,%i\n", unidad.getId(),
                     click.getPoint().x, click.getPoint().y);
            });
            selectBox.vaciarSeleccionadas();
        }
        click.resetCoords();
        return;
    }

    Elemento* clickeado = click.getClicked();
    if (clickeado->esMio()){
        //        TODO dispatch para saber si fue edificio o unidad

//        TODO obviamente le voy a tener que pasar mas info o no, no se
        printf("request info MIO de id: %i\n", clickeado->getId());
        clickeado->guiRequest(*this);
    } else if (selectBox.haySeleccion()){
        std::vector<ElementoUnidad> seleccion = selectBox.getSeleccionadas();
        std::for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                              unidad){
            printf("Unidad id: %i ataca a Elemento id: %i\n", unidad.getId(),
                   clickeado->getId());
        });
        selectBox.vaciarSeleccionadas();
    }
    click.resetCoords();
}

void ColectorDeAcciones::showEdificio() {
    guiEdificio.abrirGui(click.getPoint());
}

void ColectorDeAcciones::showHud() {
//TODO codigo para que le diga al hud que muestre otra foto
    hud.setInfo(0);
}
