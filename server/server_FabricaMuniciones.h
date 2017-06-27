#ifndef FABRICAMUNICIONES_H
#define FABRICAMUNICIONES_H

#include <stddef.h>
#include <map>
#include "server_Municion.h"

/* Fabrica que se encarga de generar instancias de la clase Munición.
 */

class FabricaMuniciones {
public:
    /* Inicializa las configuraciones de cada una de las municiones.
     * Las configuraciones son obtenidas a partir del archivo municiones.xml.
     */
    FabricaMuniciones(); 
    /* Devuelve una instancia de una munición con el tipo especificados.
     */
    Municion* getMunicion(int tipo);
private:
    /* Configuraciones de daño según tipo de munición.
     */
    std::map<int,int> municiones;
    /* Configuraciones de dimensiones según tipo
     */
    std::map<int,double> anchos;
    std::map<int,double> altos;
    
};

#endif /* FABRICAMUNICIONES_H */

