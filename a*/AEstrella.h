#ifndef AESTRELLA_H_
#define AESTRELLA_H_

#include "server_Casillero.h"

class AEstrella {
	private:
		Casillero &origen;
		Casillero &destino;
		std::vector<Casillero> listaAbierta;
		std::vector<Casillero> listaCerrada;

	public:
		AEstrella(Casillero origen, Casillero destino);

		void setEcuacion(Casillero &actual, Casillero &adyacente);

		void vecinoConMenorPeso(Casillero &resultado);

		void pathFinding(Casillero &fin);

		void getRecorrido(std::vector<Casillero> &recorrido)

		virtual ~AEstrella();
};

#endif /* AESTRELLA_H_ */
