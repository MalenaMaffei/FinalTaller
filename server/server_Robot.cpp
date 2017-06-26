
#include "server_Robot.h"

#include "server_Unidad.h"


Robot::Robot(int vida, double ancho, double alto, 
            int frecuenciaDisparo, int alcance, 
			int velocidad, int tipo, int armamento) : Unidad(vida, ancho, alto,
									frecuenciaDisparo, alcance, 
									velocidad, tipo, armamento) { }

bool Robot::subirA(Vehiculo* vehiculo) {
	return vehiculo->addConductor (this);
}

double Robot::factorTerrenoEn(Terreno* terreno) {
	return terreno->getFactor(this);
}

Robot::~Robot () { }

