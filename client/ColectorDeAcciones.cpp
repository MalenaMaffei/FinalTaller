#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/GuiEdificio.h"
#include "Header Files/Paquete.h"
#include <iostream>
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

//    TODO llevarme de aca el paquete que tenga que mandar al servidor
    if (guiEdificio.click(click.getPoint())){
        click.resetCoords();
        return;
    }
//    TODO hacer lo mismo con clicks sobre el hud

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
        //        TODO dispatch para saber si fue edificio o unidad

//        TODO obviamente le voy a tener que pasar mas info o no, no se
        printf("request info MIO de id: %s\n", clickeado->getId().c_str());
        paquete.pedirInfo(clickeado->getId());
        clickeado->guiRequest(*this);

    } else if (selectBox.haySeleccion()){
        vector<ElementoUnidad> seleccion = selectBox.getSeleccionadas();
        for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                              unidad){
              if (unidad.estaMuerto()){
                  return;
              }
            std::cout<<"Unidad id: "<<unidad.getId()<<" ataca a Elemento id: "<<
				clickeado->getId()<< std::endl;
            paquete.atacar(unidad.getId(),clickeado->getId());
            colaSalida.encolar(paquete);
        });
        selectBox.vaciarSeleccionadas();
    }

    click.resetCoords();
}

void ColectorDeAcciones::showEdificio() {
    printf("se pidio que se habra la gui\n");
    guiEdificio.abrirGui(click.getPoint());
}

void ColectorDeAcciones::showHud() {
//TODO codigo para que le diga al hud que muestre otra foto
    hud.setInfo(0);
}
