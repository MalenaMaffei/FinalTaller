#include "AEstrella.h"

AEstrella::AEstrella(std::vector<std::vector<int>> &mapa, punto &origen, punto &destino) : 
						mapa(mapa), origen(origen), destino(destino) {}

punto AEstrella::pathFinding() {
	listaAbierta.push_back(origen);

	while (listaAbierta.size() != 0) {
		punto actual = this->puntoConMenorPeso();
		listaCerrada.push_back(actual);

		if (actual == destino) {
			return actual;
		} else {
			vector<punto> adyacentes = mapa.getAdyacentes(actual);

			for (size_t i = 0; i < adyacentes.size(); ++i) {
				punto adyacente = adyacentes[i];
				if (std::find(listaAbierta.begin(), listaAbierta.end(), adyacente) == listaAbierta.end() &&
					std::find(listaCerrada.begin(), listaCerrada.end(), adyacente) == listaCerrada.end()) {

					this->setEcuacion(actual, adyacente); //falta implementar
					adyacente.setPadre(actual);
					listaAbierta.push_back(adyacente);

				} else if (std::find(listaAbierta.begin(), listaAbierta.end(), adyacente) != vector.end()) {
					/*No entiendo esta parte*/
				}
			}
		}
	}

	return actual
}

punto AEstrella::puntoConMenorPeso() {
	punto resultado = listaAbierta[0];

	if (listaAbierta.size() > 1) { //creo que es al pedo esta linea
		for (size_t i = 1; i < listaAbierta.size(); ++i) {
			if (listaAbierta[i].getPeso() < resultado.getPeso()) {
				resultado = listaAbierta[i];
			}
		}
	}
	return resultado;
}	

void AEstrella::guardarRecorrido(punto &origen, punto &destino) {
	if (destino.cmp(origen) != 0) {
		pila.push(destino);
		this->guardarRecorrido(origen, destino.getPadre());
	}
	return;
}

vector<punto> AEstrella::getRecorrido() {
	this->pathFinding();
	this->guardarRecorrido(origen, destino);
	vector<punto> recorrido;

	while (!pila.empty()) {
		recorrido.push_back(pila.top());
		pila.pop();
	}
}

AEstrella::~AEstrella() {}