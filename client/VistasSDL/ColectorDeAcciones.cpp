#include "ColectorDeAcciones.h"
#include <algorithm>
#include <vector>
ColectorDeAcciones::ColectorDeAcciones(SelectBox &selectBox, Click &click)
    : selectBox(selectBox), click(click) {}

void ColectorDeAcciones::crearAcciones() {
    if (!click.huboClick()){
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
        printf("request info MIO de id: %i\n", clickeado->getId());
    } else if (selectBox.haySeleccion()){
        std::vector<ElementoUnidad> seleccion = selectBox.getSeleccionadas();
        std::for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                              unidad){
            printf("Unidad id: %i ataca a Elemento id: %i\n", unidad.getId(),
                   clickeado->getId());
        });
        selectBox.vaciarSeleccionadas();
    } else {
        printf("request info de id: %i\n", clickeado->getId());
    }
    click.resetCoords();
}
