
#include "server_AEstrella.h"
#include <queue>
#include <math.h>
#include <iostream>

typedef std::pair< std::array<int,2>, double> elemConPrioridad_t;

class compararElementosConPrioridad {
	private:
		bool reverse;
	public:
		compararElementosConPrioridad(const bool& revparam=false) {
			reverse = revparam;
		}
		bool operator() (elemConPrioridad_t a, elemConPrioridad_t b) {
			if (reverse) return (a.second < b.second);
			return (a.second > b.second);
		}
};


const int heuristica(std::array<int, 2> origen, std::array<int, 2> destino) {
	return sqrt(pow(origen[0]-destino[0],2) + pow(origen[1]-destino[1],2)); //Manhattan
}

const double modulo(std::array<int, 2> vector) {
	return sqrt(vector[0]*vector[0] + vector[1]*vector[1]);
}

AEstrella::AEstrella(const Mapa &mapa) : mapa(mapa) {}

std::vector < std::array<double,2> >
	AEstrella::getRecorrido(const std::array<int, 2>& origen, 
							const std::array<int, 2>& destino) {
				
	std::vector< std::array<double,2> > recorrido;
	std::map <std::array<int,2>,double> costos;
	std::map <std::array<int,2>,std::array<int,2>> origenes;
	
	std::array<int,2> adyacencias[8] = { {0,1}, {1,1}, {1,0}, 
										 {1,-1}, {0,-1}, {-1,-1},
										 {-1,0}, {-1,1} };
  
	std::priority_queue<elemConPrioridad_t,
						std::vector<elemConPrioridad_t>, 
						compararElementosConPrioridad> listaAbierta;
  
	listaAbierta.push (std::make_pair(origen,0.0));
	
	costos[origen] = 0;	//No cuesta nada llegar al inicio
	origenes[origen] = origen;	//No tiene padre, lo seteo como su propio padre
	
	int maxX = mapa.obtenerDimensionX();
	int maxY = mapa.obtenerDimensionY();
	while (!listaAbierta.empty()) {
		std::array<int,2> actual = listaAbierta.top ().first;
//		std::cout<<"actual: "<<actual[0]<<","<<actual[1]<<std::endl;
		double valor = listaAbierta.top().second;
		listaAbierta.pop();
		if (actual == destino)
			break;
		
//		std::cout<<"no llegue"<<std::endl;
		for (size_t i=0; i< 8; i++) {
			std::array<int,2> adyacencia = adyacencias[i];
			int adyX = actual[0]-adyacencia[0];
			int adyY = actual[1]-adyacencia[1];
			if (adyX < 0 || adyY < 0 || adyX >= maxX || adyY >= maxY) 
				continue;
//			std::cout<<"\tadyacente: "<<adyX<<","<<adyY<<std::endl;
			std::array<int,2> adyacente = {adyX,adyY};
						
			double distancia = modulo(adyacencia);
			double nuevoCosto = costos[actual] + 
								distancia/mapa.obtenerFactorTerreno(adyacente);
//			std::cout<<"\tcosto actual: "<<costos[actual]<<std::endl;
//			std::cout<<"\tdistancia: "<<distancia<<std::endl;
//			std::cout<<"\tfactor: "<<mapa.obtenerFactorTerreno(adyacente)<<std::endl;
//			std::cout<<"\tnuevo costo: "<<nuevoCosto<<std::endl;
			bool nuevoCostoEsMenor = false;
			if (costos.count (adyacente)) {
				if (nuevoCosto<costos[adyacente]) {
					nuevoCostoEsMenor = true;
				}
			}
			
			if (!(costos.count (adyacente)) || nuevoCostoEsMenor){
				costos[adyacente] = nuevoCosto;
				double prioridad = nuevoCosto + heuristica(adyacente,destino);
				listaAbierta.push (std::make_pair(adyacente,prioridad));
				origenes[adyacente] = actual;
			}
		}	
	}
	
	if (!origenes.count(destino)) {
		return recorrido;
	}
	
	std::array<int,2> actual = destino;
	while (actual != origen) {
		recorrido.push_back({actual[0],actual[1]});
		actual = origenes[actual];
	}
	
	return recorrido;	
}

AEstrella::~AEstrella() {}

