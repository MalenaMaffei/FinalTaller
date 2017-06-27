#ifndef ROBOT_H
#define ROBOT_H

#include "server_Unidad.h"
#include "server_Vehiculo.h"
#include "server_Terreno.h"

/* Es una Unidad que representa a un robot. Son creados por las FabricaRobots.
 */

class Robot : public Unidad {
public:
    Robot(int vida, double ancho, double alto, 
            int frecuenciaDisparo, int alcance, 
            int velocidad, int tipo, int armamento);

    int calcularVelocidad(double factorTerreno) override;
    double factorTerrenoEn(Terreno* terreno);
    bool subirA(Vehiculo* vehiculo);
    virtual ~Robot();        
private:

};

#endif /* ROBOT_H */
