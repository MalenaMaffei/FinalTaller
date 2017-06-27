#ifndef TERRENO_H
#define TERRENO_H

#include "Movible.h"

class Municion;
class Robot;
class Vehiculo;

/* Cada Casillero contiene un Territorio.
 */

class Terreno {
public:
    Terreno(int tipo, double velocidadRobots, double velocidadVehiculos);
    Terreno(const Terreno& orig);
    Terreno(Terreno &&orig);
    Terreno& operator=(const Terreno& orig);
    // Double dispatch con movibles
    double getFactor(Movible* movible);
    double getFactor(Robot* robot);
    double getFactor(Vehiculo* vehiculo);
    double getFactor(Municion* municion);
    int getTipo();
    Terreno &operator=(Terreno &&orig);
    virtual ~Terreno();
private:
    /* Dependiendo del tipo de territorio se determina la velocidad de las
     * unidades
     */
    double velocidadRobots;
    double velocidadVehiculos;
    int tipo; // Pantano, Asfalto, Lava, Tierra, Agua, Carretera, Nieve, Pradera
};

#endif /* TERRENO_H */

