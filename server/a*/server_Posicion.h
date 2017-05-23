/*
 * Posicion.h
 *
 *  Created on: 21/05/2017
 *      Author: ivan
 */

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
		virtual ~Posicion();
};

#endif /* SERVER_POSICION_H_ */
