#ifndef SERVER_MAPA_H_
#define SERVER_MAPA_H_

#include <vector>
#include "server_Casillero.h"
#include "server_Posicion.h"

class Mapa {
	private:
		std::vector<std::vector<Casillero>> mapa;

	public:
		Mapa();

		void AEstrella(Posicion origen, Posicion destino);

		virtual ~Mapa();
};

#endif /* SERVER_MAPA_H_ */
