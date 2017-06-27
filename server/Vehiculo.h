#ifndef VEHICULO_H
#define VEHICULO_H

#include "Unidad.h"
#include "Terreno.h"

class Robot;

/* Es una Unidad que representa a un vehiculo. Son creados por las 
 * FabricaVehiculos.
 */

class Vehiculo : public Unidad {
public:
    Vehiculo(int vida, double ancho, double alto, 
            int frecuenciaDisparo, int alcance, 
            int velocidad, int tipo, int armamento);
    
    int calcularVelocidad(double factorTerreno) override;
    double factorTerrenoEn(Terreno* terreno);
    bool addConductor(Robot* conductor);
    virtual ~Vehiculo();
private:
    Robot* conductor;
};

#endif /* VEHICULO_H */

