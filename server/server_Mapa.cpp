
#include <fstream>
#include <sstream>
#include <iostream>
#include "server_Mapa.h"
#include "server_Terreno.h"
#include "server_FabricaTerrenos.h"

Mapa::Mapa(const std::string& nombreArchivoMapa) {
	//Creo archivo con mapa
	std::ifstream archivoMapa;	
	archivoMapa.open(nombreArchivoMapa);

	FabricaTerrenos fabrica;
	
	std::string fila;
	std::string strTipo;
	size_t i = 0;
	size_t j = 0;
	while (! archivoMapa.eof() ){
		getline (archivoMapa,fila);
		std::stringstream posiciones(fila);
		while (getline(posiciones,strTipo,' ')) {
			int tipo = -1;
			std::istringstream buffer(strTipo);
			buffer>>tipo;
			if (j == 0) {
				mapa.push_back (std::vector<Casillero>());
			}
			
			mapa[i].push_back(Casillero (fabrica.getTerreno (tipo)));
			j++;
		}
		j = 0;
		i++;
	}	
	dimensionX = mapa.size ();
	dimensionY = mapa[0].size();
}

double Mapa::obtenerVelocidad(std::array<int,2> posicion) {
	return mapa[posicion[0]][posicion[1]].getFactorTerreno();
}

int Mapa::obtenerDimensionX() {
  return dimensionX;
}

int Mapa::obtenerDimensionY() {
  return dimensionY;
}


Mapa::~Mapa() {

}

