#ifndef SERVER_Armamento_H_
#define SERVER_Armamento_H_

class Armamento {
	private:
		int danio;
		bool animacion;

	public:
		Armamento(int danio);

		void atacarA(Objeto &objetoAtacado);

		virtual ~Armamento();
}




#endif /* SERVER_Armamento_H_ */