#ifndef SERVER_OBJETO_H_
#define SERVER_OBJETO_H_

class Objeto {
	private:
		int id;
		int vida;

	public:
		Objeto(int id, int vida);

		bool estaVivo();

		void recibirAtaque(int danio);

		virtual ~Objeto();
}




#endif /* SERVER_Objeto_H_ */