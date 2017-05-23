#ifndef SERVER_ARMAMENTO_H_
#define SERVER_ARMAMENTO_H_

#include "server_Posicion.h"

class Armamento {
	private:
		int id;
		int danio;
		std::vector<Posicion> posiciones;

	public:
		Armamento(int id, int danio);

		void atacarA(Objeto &atacado);

		virtual ~Armamento();
}




#endif /* SERVER_Armamento_H_ */