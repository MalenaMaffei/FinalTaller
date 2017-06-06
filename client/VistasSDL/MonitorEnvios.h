

#ifndef MONITORENVIOS_H
#define MONITORENVIOS_H
#include "common_Paquete.h"

class MonitorEnvios {
public:
    MonitorEnvios();
    void agregarPaquete(Paquete& paquete);
    Paquete& obtenerPaquete();
    virtual ~MonitorEnvios();
private:
    std::vector<Paquete> paquetes;
//    std::mutex &m;
    //Cola de envios
};

#endif /* MONITORENVIOS_H */

