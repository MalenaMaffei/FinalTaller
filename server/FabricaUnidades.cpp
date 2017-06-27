
#include "FabricaUnidades.h"
#include <iostream>
#include <vector>

#define FUERTE 3
#define ROBOTS 4
#define VEHICULOS 5

FabricaUnidades::FabricaUnidades() { }

Unidad* FabricaUnidades::getUnidad(int tipo) {
	if (tipo>=6 && tipo<=10) {
		return this->getRobot(tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->getVehiculo(tipo);
	}
	return NULL;
}

Robot* FabricaUnidades::getRobot(int tipo) {
	return this->fabricaRobots.getRobot(tipo);
}

Vehiculo* FabricaUnidades::getVehiculo(int tipo) {
	return this->fabricaVehiculos.getVehiculo(tipo);
}

int FabricaUnidades::getTiempo(int tipo) {
  	if (tipo>=6 && tipo<=10) {
		return this->fabricaRobots.getTiempo(tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->fabricaVehiculos.getTiempo(tipo);
	}
	return -1;
}

double FabricaUnidades::getAlcance(int tipo) {
	if (tipo>=6 && tipo<=10) {
		return this->fabricaRobots.getAlcance(tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->fabricaVehiculos.getAlcance(tipo);
	}
	return -1;
}

std::vector<int> FabricaUnidades::getUnidadesPosibles(int tipo, int nivel) {
	std::vector<int> tiposPosibles;
	if (tipo == FUERTE || tipo == ROBOTS) {
		this->fabricaRobots.getRobotsPosibles(nivel, tiposPosibles);
	}
	if (tipo == FUERTE || tipo == VEHICULOS) {
		this->fabricaVehiculos.getVehiculosPosibles(nivel, tiposPosibles);
	}
	return tiposPosibles;
}


FabricaUnidades::~FabricaUnidades() { }
