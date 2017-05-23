#ifndef SERVER_POSICION_H_
#define SERVER_POSICION_H_

class Posicion {
	private:
		int x;
		int y;

	public:
		Posicion(int x, int y);

		int getX();

		int getY();

		void ocupantes(std::vector<Objeto> &ocupantes);

		virtual ~Posicion();
};

#endif /* SERVER_POSICION_H_ */
