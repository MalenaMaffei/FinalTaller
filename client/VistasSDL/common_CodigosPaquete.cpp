#include "Header Files/common_CodigosPaquete.h"
#define COMIENZO_UNIDADES 6

bool CodigosPaquete::esUnidad(int tipo) {
    return tipo >= COMIENZO_UNIDADES;
}
