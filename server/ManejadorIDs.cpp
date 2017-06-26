
#include "ManejadorIDs.h"

ManejadorIDs::ManejadorIDs () : proximoIDMovible (0),
								proximoIDEdificio (0),
								proximoIDInmovible (0),
								proximoIDMunicion (0) { }

std::string ManejadorIDs::getIDMunicion() {
	/* Los ids de las Municiones no tienen prefijo identificatorio y tienen un 
	 * largo de 3, por lo tanto puede haber un máximo de 1000 municiones.
	 */
	// TODO reutilizar IDs de municiones
	std::string id = rellenador.rellenar(proximoIDMunicion++,3);
	return id;
}

std::string ManejadorIDs::getIDEdificio() {
  	/* Los ids de los Edificios están prefijados por la letra "i" y tienen un 
	 * largo de 3, por lo tanto puede haber un máximo de 100 edificios.
	 */
	// TODO reemplazar prefijo "i" por "e"
	std::string id = "i" + rellenador.rellenar(proximoIDInmovible++,2);
	return id;	
}

std::string ManejadorIDs::getIDMovible() {
	/* Los ids de las Unidades están prefijados por la letra "m" y tienen un 
	 * largo de 3, por lo tanto puede haber un máximo de 100 unidades
	 * (Robot o Vehiculo).
	 */
	std::string id ="m" + rellenador.rellenar(proximoIDMovible++,2);
	return id;
}

std::string ManejadorIDs::getIDInmovible() {
	/* Los ids de los Inmovibles están prefijados por la letra "i" y tienen un 
	 * largo de 3, por lo tanto puede haber un máximo de 100 inmovibles 
	 * (Bandera o Bloque).
	 */
	std::string id = "i" + rellenador.rellenar(proximoIDInmovible++,2);
	return id;
}

ManejadorIDs::~ManejadorIDs () { }


