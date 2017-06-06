

#include "MonitorEnvios.h"

MonitorEnvios::MonitorEnvios () { }

void MonitorEnvios::agregarPaquete(Paquete& paquete) {
	paquetes.push_back (paquete);
}

Paquete& MonitorEnvios::obtenerPaquete() {
	Paquete paquete = paquetes.front();
	paquetes.erase (paquetes.begin());
	return paquete;
}

MonitorEnvios::~MonitorEnvios () { }

