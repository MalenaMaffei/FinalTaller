#include "ColectorDeAcciones.h"
#include <algorithm>
#include <vector>
ColectorDeAcciones::ColectorDeAcciones(SelectBox &selectBox, Click &click)
    : selectBox(selectBox), click(click) {}

void ColectorDeAcciones::crearAcciones() {
    Elemento* clickeado = click.getClicked();
    if (clickeado == nullptr){
        return;
    }
    if (clickeado->esMio()){
        printf("request info de id: %i\n", clickeado->getId());
    } else if (selectBox.haySeleccion()){
        std::vector<ElementoUnidad> seleccion = selectBox.getSeleccionadas();
        std::for_each(seleccion.begin(), seleccion.end(), [&](ElementoUnidad
                                                              unidad){
            printf("Unidad id: %i ataca a Elemento id: %i\n", unidad.getId(),
                   clickeado->getId());
        });
        selectBox.vaciarSeleccionadas();
    }


}
