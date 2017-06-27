#ifndef FABRICATERRENOS_H
#define FABRICATERRENOS_H

#include <map>
#include "Terreno.h"

/* Fabrica que se encarga de generar instancias de la clase Terreno.
 */

class FabricaTerrenos {
public:
    /* Inicializa las configuraciones de cada una de los tipos de terreno.
     * Las configuraciones son obtenidas a partir del archivo terrenos.xml.
     */
    FabricaTerrenos();
    /* Devuelve una instancia de un terreno con el tipo especificados.
     */
    Terreno getTerreno(int tipo);
    virtual ~FabricaTerrenos();
private:
    /* Configuraciones de factor de velocidad según tipo de terreno.
     */
    std::map<int, double> velocidadesVehiculos;
    std::map<int, double> velocidadesRobots;
};

#endif /* FABRICATERRENOS_H */

