#ifndef SERVER_POSICION_H_
#define SERVER_POSICION_H_

#include <vector>
#include <tuple>

class Posicion {
	private:
		Terreno &terreno;
		int x;
		int y;
		Objeto &ocupante;
		std::vector<Posicion> &vecinos;
		int distG;
		int distH;
		Posicion &padre;

	public:
		Posicion(Terreno &terreno);

		int getX();

		int getY();

		void setVecinos(std::vector<Posicion> &nuevosVecinos);

		void getVecinos(std::vector<Posicion> &resultado);

		void getPos(posicion &posCas);

		bool cmp(Posicion &other);

		bool estaOcupado();

		void setG(int distancia);

		int getG();

		bool estaEnDiagonal(posicion &destinoPos);

		int getFactorTerreno();

		int distanciaG(Posicion &destino);

		void setH(int distancia);

		int getH();

		int distanciaH(Posicion &destino);

		int getF();

		void setPadre(Posicion &nuevoPadre);

		void getPadre(Posicion &resutlado);

		virtual ~Posicion();
};
