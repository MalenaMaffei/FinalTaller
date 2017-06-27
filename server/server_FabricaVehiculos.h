#ifndef FABRICAVEHICULOS_H
#define FABRICAVEHICULOS_H

#include "server_Vehiculo.h"
#include <map>
#include <vector>

/* Fabrica que se encarga de generar instancias de la clase Vehiculo.
 */

class FabricaVehiculos {
public:
    /* Inicializa las configuraciones de cada uno de los vehiculos.
     * Las configuraciones son obtenidas a partir del archivo vehiculos.xml.
     */
    FabricaVehiculos();
    /* Devuelve una instancia de un vehiculo con el tipo especificados.
     */
    Vehiculo* getVehiculo(int tipo);
    /* Devuelve el tiempo base de creación de un Vehiculo del tipo especificado.
     */    
    int getTiempo(int tipo);
    /* Devuelve el alcance de los ataques de un Vehiculo del tipo especificado.
     */    
    double getAlcance(int tipo);
    /* Devuelve los tipos de Vehiculos que puede construir un Edificio con el
     * nivel especificado.
     */    
    void getVehiculosPosibles(int nivel, std::vector<int>& tiposPosibles);
private:
    /* Configuraciones propias de los vehiculos
     */
    std::map<int,int> armamentos;
    std::map<int,double> frecuencias;
    std::map<int,int> alcances;
    std::map<int,int> vidas;
    std::map<int,int> velocidades;
    /* Configuraciones de condicones de fabricación
     */
    std::map<int,int> cantidades;
    std::map<int,int> tiempos;
    std::map<int,int> niveles;    
    /* Configuraciones de dimensiones según tipo
     */
    std::map<int,double> anchos;
    std::map<int,double> altos;
};

#endif /* FABRICAVEHICULOS_H */

