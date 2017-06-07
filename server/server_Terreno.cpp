
#include "server_Terreno.h"

Terreno::Terreno(int tipo, int velocidadRobots, int velocidadVehiculos) : 
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

double Terreno::getFactor() {
	return this->velocidadRobots;
}

int Terreno::getTipo() {
	return this->tipo;
}

Terreno::~Terreno () { }


