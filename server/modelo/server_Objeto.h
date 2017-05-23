#ifndef SERVER_OBJETO_H_
#define SERVER_OBJETO_H_

class Objeto {
	private:
		int id;
		int vida;
		Posicion &pos;

	public:
		Objeto(int id, int vida);

		void getPos(Posicion &resultado);

		bool estaVivo();

		void recibirAtaque(int danio);

		virtual ~Objeto();
}




#endif /* SERVER_Objeto_H_ */