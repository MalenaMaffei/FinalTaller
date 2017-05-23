#ifndef SERVER_CASILLERO_H_
#define SERVER_CASILLERO_H_

#include <vector>
#include <tuple>

typedef std::tuple<int,int> posicion;

class Casillero {
	private:
		std::vector<Casillero> vecinos;
		posicion posCentro;
		bool ocupado;
		int distG;
		int distH;
		Casillero &padre;
		Terreno terreno;

	public:
		Casillero(std::vector<Casillero> &vecinos);

		void getVecinos(std::vector<Casillero> &resultado);

		void getPos(posicion &posCas);

		bool cmp(Casillero &other);

		bool estaOcupado();

		void setG(int distancia);

		int getG();

		bool estaEnDiagonal(posicion &destinoPos);

		int getFactorTerreno();

		int distanciaG(Casillero &destino);

		void setH(int distancia);

		int getH();

		int distanciaH(Casillero &destino);

		int getF();

		void setPadre(Casillero &nuevoPadre);

		void getPadre(Casillero &resutlado);

		virtual ~Casillero();
};
