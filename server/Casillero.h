#ifndef SERVER_CASILLERO_H
#define SERVER_CASILLERO_H

#include <tuple>
#include "Terreno.h"
#include "Movible.h"

/* El Mapa está compuesto por casilleros.
 */

class Casillero {
public:
    Casillero(Terreno &&terreno);
    Casillero(const Casillero& orig);
    Casillero& operator=(const Casillero& orig);
    /* Devuelve el factor de terreno para el movible pasado por parametro del
     * Territorio presente en el casillero.
     */
    double getFactorTerreno(Movible* movible);
    /* Devuelve el tipo de Territorio presente en el casillero.
     */
    int getTipoTerreno();
    virtual ~Casillero();

private:
    /* Cada casillero contienen un Terreno.
     */
    Terreno terreno;
};

#endif /* SERVER_CASILLERO_H */
