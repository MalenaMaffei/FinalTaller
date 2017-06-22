/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FabricaUnidades.cpp
 * Author: usuario
 * 
 * Created on 21 de junio de 2017, 18:34
 */

#include "FabricaUnidades.h"
#include <iostream>

#define FUERTE 3
#define ROBOTS 4
#define VEHICULOS 5

FabricaUnidades::FabricaUnidades () { }

Unidad* FabricaUnidades::getUnidad(int tipo) {
	if (tipo>=6 && tipo<=10) {
		return this->getRobot (tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->getVehiculo (tipo);
	}
	return NULL;
}

Robot* FabricaUnidades::getRobot(int tipo) {
	return this->fabricaRobots.getRobot (tipo);
}

Vehiculo* FabricaUnidades::getVehiculo(int tipo) {
	return this->fabricaVehiculos.getVehiculo (tipo);
}

int FabricaUnidades::getCantidad(int tipo) {
	if (tipo>=6 && tipo<=10) {
		return this->fabricaRobots.getCantidad (tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->fabricaVehiculos.getCantidad (tipo);
	}
	return -1;
}

int FabricaUnidades::getTiempo(int tipo) {
  	if (tipo>=6 && tipo<=10) {
		return this->fabricaRobots.getTiempo (tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->fabricaVehiculos.getTiempo (tipo);
	}
	return -1;
}

double FabricaUnidades::getAlcance(int tipo) {
	if (tipo>=6 && tipo<=10) {
		return this->fabricaRobots.getAlcance (tipo);
	} else if (tipo>=11 && tipo<=16) {
		return this->fabricaVehiculos.getAlcance (tipo);
	}
	return -1;
}

std::vector<int> FabricaUnidades::getUnidadesPosibles(int tipo, int nivel) {
	std::vector<int> tiposPosibles;
	if (tipo == FUERTE || tipo == ROBOTS) {
		this->fabricaRobots.getRobotsPosibles (nivel, tiposPosibles);
	}
	if (tipo == FUERTE || tipo == VEHICULOS) {
		this->fabricaVehiculos.getVehiculosPosibles (nivel, tiposPosibles);
	}
	return tiposPosibles;
}


FabricaUnidades::~FabricaUnidades () { }

