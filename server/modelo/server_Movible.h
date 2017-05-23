#ifndef SERVER_MOVIBLE_H_
#define SERVER_MOVIBLE_H_

#include "server_Posicion.h"

class Movible : public Objeto {
	private:
		Armamento &armamento;
		std::vector<Posicion> posiciones;

	public:
		Movible(int id, int vida, Armamento &armamento);

		virtual ~Movible();
}




#endif /* SERVER_Movible_H_ */