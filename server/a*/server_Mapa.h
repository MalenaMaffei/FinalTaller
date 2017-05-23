#ifndef SERVER_MAPA_H_
#define SERVER_MAPA_H_

#include <vector>
#include "server_Casillero.h"
#include "server_Posicion.h"
#include "server_AEstrella.h"

class Mapa {
	public:
		Mapa();
		void AEstrella(Casillero origen, Casillero destino);
		virtual ~Mapa();
	private:
            std::vector< std::vector<Casillero> > mapa;

};

#endif /* SERVER_MAPA_H_ */
