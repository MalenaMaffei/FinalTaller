#include "server_Robot.h"

Robot::Robot(int id, int vida, Armamento &armamento, int freqDisp, int alcance, 
							int ptosEstruc, int velBase, int tiempoFabr, int nivelTec) : 
								Movible(id, vida, armamento, freqDisp, alcance, ptosEstruc, velBase, tiempoFabr, nivelTec) {}
