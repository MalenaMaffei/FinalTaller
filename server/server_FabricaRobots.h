#ifndef FABRICAROBOTS_H
#define FABRICAROBOTS_H

#include <map>
#include <time.h>
#include "server_Robot.h"

/* Fabrica que se encarga de generar instancias de la clase Robot.
 */

class FabricaRobots {
public:
    /* Inicializa las configuraciones de cada uno de los robots.
     * Las configuraciones son obtenidas a partir del archivo robots.xml.
     */
    FabricaRobots();
    /* Devuelve una instancia de un robot con el tipo especificados.
     */
    Robot* getRobot(int tipo);
    /* Devuelve el tiempo base de creación de un Robot del tipo especificado.
     */    
    int getTiempo(int tipo);
    /* Devuelve el alcance de los ataques de un Robot del tipo especificado.
     */    
    double getAlcance(int tipo);
    /* Devuelve los tipos de Robots que puede construir un Edificio con el
     * nivel especificado.
     */    
    void getRobotsPosibles(int nivel, std::vector<int>& tiposPosibles);
private:    
    /* Configuraciones propias de los robots
     */
    std::map<int,int> armamentos;
    std::map<int,double> frecuencias;
    std::map<int,int> alcances;
    std::map<int,int> vidas;
    std::map<int,int> velocidades;
    /* Configuraciones de condicones de fabricación
     */
    std::map<int,int> cantidades;
    std::map<int,time_t> tiempos;
    std::map<int,int> niveles;
    /* Configuraciones de dimensiones según tipo
     */
    std::map<int,double> anchos;
    std::map<int,double> altos;
};

#endif /* FABRICAROBOTS_H */

