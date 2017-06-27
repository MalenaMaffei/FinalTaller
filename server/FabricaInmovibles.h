#ifndef FABRICAINMOVIBLES_H
#define FABRICAINMOVIBLES_H

#include "Inmovible.h"
#include "Bloque.h"
#include "Bandera.h"
#include <map>
#include <string>

/* Fabrica que se encarga de generar instancias de clases herederas de 
 * Inmovible.
 */

class FabricaInmovibles {
public:
    /* Inicializa las configuraciones de cada uno de los inmovibles.
     * Las configuraciones son obtenidas a partir del archivo inmovibles.xml.
     */
    FabricaInmovibles();
    /* Devuelve una instancia de un inmovible con el tipo, coordenadas
     * y id especificados.
     */
    Inmovible* getInmovible(int tipo, double x, double y, std::string id);
    virtual ~FabricaInmovibles();

private:
    /* Método interno (llamado por getInmovible) que devuelve un bloque 
     * inicializado.
     */
    Bloque* getBloque(int tipo, double x, double y, std::string id);
    /* Método interno (llamado por getInmovible) que devuelve una bandera 
     * inicializado.
     */
    Bandera* getBandera(int tipo, double x, double y, std::string id);
    /* Configuraciones de vidas según tipo
     */
    std::map<int,int> vidas;
    /* Configuraciones de dimensiones según tipo
     */
    std::map<int,double> anchos;
    std::map<int,double> altos;
};

#endif /* FABRICAINMOVIBLES_H */

