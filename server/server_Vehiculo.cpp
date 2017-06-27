
#include "server_Vehiculo.h"
#include "server_Robot.h"
#include <iostream>

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

int Vehiculo::calcularVelocidad(double factorTerreno) {
	double vida = double(this->vida)/double(this->vidaTotal);
	std::cout<<"Vida de robot = "<<vida<<std::endl;
	return int(velocidad*factorTerreno*vida);
}

Vehiculo::~Vehiculo () { 
	//Actualmente nunca se inicializa un conductor, pero en un futuro, en caso 
	//de agregar la funcionalidad, se derá destruido al destruirse el vehiculo
	if (conductor)
		delete conductor;
}

