
#include "server_Vehiculo.h"
#include "server_Robot.h"

Vehiculo::Vehiculo(int vida, double ancho, double alto, 
					int frecuenciaDisparo, int alcance, 
					int velocidad, int tipo, int armamento) : 
								Unidad(vida, ancho, alto,
									frecuenciaDisparo, alcance, 
									velocidad, tipo, armamento), 
									conductor(NULL) { }

double Vehiculo::factorTerrenoEn(Terreno* terreno) {
	return terreno->getFactor(this);
}

bool Vehiculo::addConductor(Robot* conductor) { 
	//No me puedo subir a vehiculo ocupado
	if (this->conductor) {
		return false;
	}
	this->conductor = conductor;
	return true;
}

Vehiculo::~Vehiculo () { }

