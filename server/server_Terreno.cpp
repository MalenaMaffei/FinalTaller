
#include "server_Terreno.h"
#include "server_Municion.h"
#include "server_Robot.h"
#include "server_Vehiculo.h"
#include <iostream>

#define VEL_MUNICIONES 1

Terreno::Terreno(int tipo, double velocidadRobots, double velocidadVehiculos) : 
									tipo(tipo),
									velocidadRobots(velocidadRobots),
									velocidadVehiculos(velocidadVehiculos){ }

Terreno::Terreno(const Terreno& orig) : 
									tipo(orig.tipo),
									velocidadRobots(orig.velocidadRobots),
									velocidadVehiculos(orig.velocidadVehiculos) 
									{ }

Terreno& Terreno::operator=(const Terreno& orig) {
	tipo = orig.tipo;
	velocidadRobots = orig.velocidadRobots;
	velocidadVehiculos = orig.velocidadVehiculos;
	return *this;
}

Terreno::Terreno(Terreno &&orig) : tipo(orig.tipo), 
									velocidadRobots(orig.velocidadRobots),
									velocidadVehiculos(orig.velocidadVehiculos)
									{ }

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


