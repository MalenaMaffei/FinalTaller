
#include "server_Terreno.h"
#include "server_Municion.h"
#include "server_Robot.h"
#include "server_Vehiculo.h"
#include <iostream>

#define VEL_MUNICIONES 1

Terreno::Terreno(int tipo, double velocidadRobots, double velocidadVehiculos) : 
									velocidadRobots(velocidadRobots),
									velocidadVehiculos(velocidadVehiculos), 
									tipo(tipo){ }

Terreno::Terreno(const Terreno& orig) : 
									velocidadRobots(orig.velocidadRobots),
									velocidadVehiculos(orig.velocidadVehiculos), 
									tipo(orig.tipo) { }

Terreno& Terreno::operator=(const Terreno& orig) {
	tipo = orig.tipo;
	velocidadRobots = orig.velocidadRobots;
	velocidadVehiculos = orig.velocidadVehiculos;
	return *this;
}

Terreno::Terreno(Terreno &&orig) : 	velocidadRobots(orig.velocidadRobots),
									velocidadVehiculos(orig.velocidadVehiculos),
									tipo(orig.tipo) { }

Terreno &Terreno::operator=(Terreno &&orig) {
	this->tipo = orig.tipo;
	this->velocidadRobots = orig.velocidadRobots;
	this->velocidadVehiculos = orig.velocidadVehiculos;
	return *this;
}

double Terreno::getFactor(Movible* movible) {
	return movible->factorTerrenoEn(this);
}

double Terreno::getFactor(Robot* robot) {
	return this->velocidadRobots;
}

double Terreno::getFactor(Vehiculo* vehiculo) {
	return this->velocidadVehiculos;
}

double Terreno::getFactor(Municion* municion) {
	return VEL_MUNICIONES;
}

int Terreno::getTipo() {
	return this->tipo;
}

Terreno::~Terreno () { }


