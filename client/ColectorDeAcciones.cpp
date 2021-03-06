#include "Header Files/ColectorDeAcciones.h"
#include "Header Files/Hud.h"
#include "Header Files/GuiFabrica.h"
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
                                       GuiFabrica &guiEdificio,
                                       ColaPaquetes &salida)
    : selectBox(selectBox), click(click), guiEdificio(guiEdificio), hud(hud),
      colaSalida(salida){}

void ColectorDeAcciones::crearAcciones() {
//    Reenvío los paquetes pidiendo información si las guis están activas.
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

//    Si se hizo click sobre las guis, releva si el usuario hizo algo para
// mandar el paquete
    if (guiEdificio.click(clicked) || hud.click(click)){
        if (guiEdificio.huboSeleccion()){
            paquete.crear(guiEdificio.getIdFabrica(),
                        guiEdificio.getTipoSeleccionado());
            colaSalida.encolar(paquete);
        }
        click.resetCoords();
        return;
    }

// Si no se clickeo a un elemento, chequea si habia seleccion para mandar a
// las unidades al punto clickeado.
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

//  Si llegué hasta acá, había un clickeado. Si hay seleccion y el clickeado
// es enemigo, lo voy a atacar. Si no era ese el caso, pido informacion del
// clickeado.
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

// Los elementos llaman a alguna de estas en guiRequest, depende de si es una
// estructura o una unidad llama al gui de fabricar o el de ver la vida.
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
