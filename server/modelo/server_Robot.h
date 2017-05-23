#ifndef SERVER_ROBOT_H_
#define SERVER_ROBOT_H_

class Robot : public Movible {
	private:
		Armamento &armamento;

	public:
		Robot(int id, int vida, Armamento &armamento);

		virtual ~Robot();
}




#endif /* SERVER_Movible_H_ */