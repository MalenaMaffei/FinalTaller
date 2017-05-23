#include "server_Movible.h"

Movible::Movible(int id, int vida, Armamento &armamento) : 
							Objeto(id, vida), armamento(armamento) {}

