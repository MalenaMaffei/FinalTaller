#ifndef FABRICAUNIDADES_H
#define FABRICAUNIDADES_H

#include "FabricaRobots.h"
#include "FabricaVehiculos.h"
#include <vector>
/* Fabrica que se encarga de generar instancias de clases herederas de 
 * Unidad.
 */

class FabricaUnidades {
public:
    FabricaUnidades();
    /* Devuelve una instancia de una Unidad con el tipo especificado.
     * Internamente llama a getUnidad o getRobot.
     */
    Unidad* getUnidad(int tipo);
    /* Devuelve una instancia de un Robot con el tipo especificado.
     * Internamente llama a FabricaRobots.
     */    
    Robot* getRobot(int tipo);
    /* Devuelve una instancia de un Robot con el tipo especificado.
     * Internamente llama a FabricaVehiculos.
     */    
    Vehiculo* getVehiculo(int tipo);
    /* Devuelve el tiempo base de creación de una Unidad del tipo especificado.
     */    
    int getTiempo(int tipo);
    /* Devuelve el alcance de los ataquesde una Unidad del tipo especificado.
     */    
    double getAlcance(int tipo);
    /* Devuelve los tipos de Unidades que puede construir un Edificio de tipo y
     * nivel especificado.
     */    
    std::vector<int> getUnidadesPosibles(int tipo, int nivel);

    virtual ~FabricaUnidades();

private:
    /* Fabricas de Robots y Vehiculos que almacenan las configuraciones 
     * internas iniciales.
     */
    FabricaRobots fabricaRobots;
    FabricaVehiculos fabricaVehiculos;
};

#endif /* FABRICAUNIDADES_H */

