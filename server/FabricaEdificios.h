#ifndef FABRICAEDIFICIOS_H
#define FABRICAEDIFICIOS_H

#include "Edificio.h"
#include <array>
#include <map>

/* Fabrica que se encarga de generar instancias de clases herederas de 
 * Edificio.
 */

class FabricaEdificios {
public:
    /* Inicializa las configuraciones de cada uno de los edificios.
     * Las configuraciones son obtenidas a partir del archivo edificios.xml.
     */
    FabricaEdificios();
    /* Devuelve una instancia de un edificio con el tipo, equipo, coordenadas
     * y id especificados.
     */
    Edificio* getEdificio(int tipo, int equipo, double x, double y, 
                            std::string id);
    virtual ~FabricaEdificios();
private:
    /* Configuraciones de vidas según tipo
     */
    std::map<int,int> vidas;
    /* Configuraciones de dimensiones según tipo
     */
    std::map<int,double> anchos;
    std::map<int,double> altos;
};

#endif /* FABRICAEDIFICIOS_H */

