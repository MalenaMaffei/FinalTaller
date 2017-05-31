#include "FabricaVista.h"
#define POS_CAMINAR 0
#define POS_DISPARO 1
FabricaVista::FabricaVista(std::map<int, Vista *> &vistas,
                           std::map<int,
                                    std::vector<VistaDireccionada *>> &vistasDireccionadas)
    : vistas(vistas), vistasDireccionadas(vistasDireccionadas) {

//    TODO ver si pregunto aca si hay que crearla o no, lo podria usar como
// interfaz de las vistas y ya? en ese caso, no deberia tener referencias
// sino que los mapas deberian ser mios al 100% y este seria un vistaManager?





}
