#ifndef SERVER_Armamento_H_
#define SERVER_Armamento_H_

#include "server_Posicion.h"

class Armamento {
	private:
		int danio;
		Posicion &origen;

	public:
		Armamento(int danio);

		void atacarA(Objeto &atacado);

		virtual ~Armamento();
}




#endif /* SERVER_Armamento_H_ */