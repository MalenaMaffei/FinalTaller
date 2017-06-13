
#include "server_Edificio.h"
#include "server_Unidad.h"
#include "server_Bloque.h"
#include "server_Municion.h"
#include "server_Bandera.h"
#include <iostream>
#include <cmath>

Edificio::Edificio (int vida, double ancho, double alto, 
					int idEquipo, int tipo) :	
									Inmovible(vida,ancho,
											alto, tipo),
									idEquipo(idEquipo), 
									tipo (-1),
									construccionesRealizadas (0),
									nivel (1) { }

void Edificio::colisionar(Objeto& objeto) {
	objeto.colisionar(*this);
}

void Edificio::colisionar(Municion& municion) {
	this->recibirDanio(municion.getDanio ());
}	

void Edificio::colisionar (Unidad& personaje) {
	//No hago nada si colisiona una persona con un edificio
}

void Edificio::colisionar(Bloque& bloque) {
	//No hago nada si colisiona bloque con un edificio
}

void Edificio::colisionar(Edificio& edificio) {
	//No hago nada si colisiona edificio con un edificio
}

void Edificio::colisionar (Bandera& bandera) {
	//No hago nada si bandera colisiona con fabrica
}

void Edificio::setFabricacion(int tiempoBase, int territorios, int tipo) {
	tiempoFabricacion = (double(tiempoBase)/double(territorios))/
								std::sqrt(double(vida)/double(vidaTotal));
	tiempoParaFabricacion = tiempoFabricacion;
}

Edificio::~Edificio () { }

int Edificio::debeCrear () {
  	if (tiempoParaFabricacion == 0 && tipo!=-1) {
		tiempoParaFabricacion = tiempoFabricacion;
		++construccionesRealizadas;
		if (construccionesRealizadas%2) {
			++nivel;
		}
		return tipo; //Devuelvo tipo a crear
	}
//	std::cout<<tiempoParaFabricacion<<"/"<<tiempoFabricacion<<std::endl;
	if (tiempoParaFabricacion)
		tiempoParaFabricacion--;
	return -1;	//empty string
}

int Edificio::getNivel() {
	return nivel;
}

bool Edificio::estaCreando() {
	return tipo!=-1; //Si esta en -1 no esta creando nada
}