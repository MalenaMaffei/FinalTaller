#ifndef SERVER_Movible_H_
#define SERVER_Movible_H_

class Movible : public Objeto {
	private:
		Armamento &armamento;

	public:
		Movible(int vida);

		virtual ~Movible();
}




#endif /* SERVER_Objeto_H_ */