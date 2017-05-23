#ifndef SERVER_MOVIBLE_H_
#define SERVER_MOVIBLE_H_

class Movible : public Objeto {
	private:
		Armamento &armamento;

	public:
		Movible(int id, int vida, Armamento &armamento);

		virtual ~Movible();
}




#endif /* SERVER_Movible_H_ */