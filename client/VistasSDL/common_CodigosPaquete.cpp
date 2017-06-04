#include "Header Files/common_CodigosPaquete.h"
#define COMIENZO_UNIDADES 6
#define FIN_UNIDADES 16
#define COMIENZO_ROBOTS 6
#define FIN_ROBOTS 11

bool CodigosPaquete::esUnidad(int tipo) {
    return tipo >= COMIENZO_UNIDADES;
}

int CodigosPaquete::unidadesBegin() {
    return COMIENZO_UNIDADES;
}

int CodigosPaquete::unidadesEnd() {
    return FIN_UNIDADES;
}
bool CodigosPaquete::esRobot(int tipo) {
    return esUnidad(tipo) && tipo<= 11;
}
