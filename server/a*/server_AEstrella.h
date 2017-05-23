#ifndef SERVER_AESTRELLA_H_
#define SERVER_AESTRELLA_H_

#include "server_Posicion.h"

class AEstrella {
	private:
		Posicion &origen;
		Posicion &destino;
		std::vector<Posicion> listaAbierta;
		std::vector<Posicion> listaCerrada;

	public:
		AEstrella(Posicion origen, Posicion destino);

		void setEcuacion(Posicion &actual, Posicion &adyacente);

		void vecinoConMenorPeso(Posicion &resultado);

		void pathFinding(Posicion &fin);

		void getRecorrido(std::vector<Posicion> &recorrido);

		virtual ~AEstrella();
};

#endif /* SERVER_AESTRELLA_H_ */
