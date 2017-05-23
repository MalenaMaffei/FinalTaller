#include "server_AEstrella.h"

AEstrella::AEstrella(Posicion origen, Posicion destino) :
							origen(origen), destino(destino) {}

void AEstrella::vecinoConMenorPeso(Posicion &resultado) {
	resultado = listaAbierta[0];
	for(size_t i = 1; i < listaAbierta.size(); ++i) {
		if(listaAbierta[i].getF() < resultado.getF()) {
			resultado = listaAbierta[i];
		}
	}
	listaAbierta.erase(std::remove(listaAbierta.begin(),
									listaAbierta.end(), resultado), listaAbierta.end());
}

void AEstrella::setEcuacion(Posicion &actual, Posicion &adyacente) {
	int distH = actual.distanciaH(adyacente);
	int distG = actual.distanciaG(adyacente);

	adyacente.setH(distH + actual.getH());
	adyacente.setG(distG + actual.getG());
}

void AEstrella::pathFinding(Posicion &fin) {
	listaAbierta.push_back(origen);
	while(listaAbierta.size() != 0) {
		Posicion actual;
		this->vecinoConMenorPeso(actual);
		listaCerrada.push_back(actual);

		if (actual.cmp(destino)) {
			fin = actual;
			return;

		} else {
			std::vector<Posicion> adyacentes;
			actual.getVecinos(adyacentes);

			for (size_t i = 0; i < adyacentes.size(); ++i) {
				Posicion adyacente = adyacentes[i];
				
				if (!adyacente.estaOcupado()) {
					if (std::find(listaAbierta.begin(), listaAbierta.end(), adyacente) == listaAbierta.end() &&
						std::find(listaCerrada.begin(), listaCerrada.end(), adyacente) == listaCerrada.end()) {
						this->setEcuacion(actual, adyacente);
						adyacente.setPadre(actual);
						listaAbierta.push_back(adyacente);

					} else if (std::find(listaAbierta.begin(), listaAbierta.end(), adyacente) != vector.end()) {
						if (adyacente.getG() < actual.getG()) {
							this->setEcuacion(actual, adyacente);
							adyacente.setPadre(actual);
						}
					}
				}
			}
		}
	}
}

void AEstrella::getRecorrido(std::vector<Posicion> &recorrido) {
	Posicion actual;
	this->pathFinding(actual);

	while (actual != origen) {
		recorrido.push_back(actual);
		Posicion aux;
		actual.getPadre(aux);
		actual = aux;
	}
	recorrido.push_back(origen);
}

AEstrella::~AEstrella() {}

