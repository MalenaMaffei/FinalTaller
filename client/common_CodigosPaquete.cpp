#include "Header Files/common_CodigosPaquete.h"
#include <string>
#define COMIENZO_UNIDADES 6
#define FIN_UNIDADES 16
#define COMIENZO_ROBOTS 6
#define FIN_ROBOTS 11
#define COMIENZO_TANQUES 12
#define FIN_TANQUES 16

bool CodigosPaquete::esUnidad(int tipo) {
    return tipo >= COMIENZO_UNIDADES && tipo <= FIN_UNIDADES;
}

int CodigosPaquete::unidadesBegin() {
    return COMIENZO_UNIDADES;
}

int CodigosPaquete::unidadesEnd() {
    return FIN_UNIDADES;
}

bool CodigosPaquete::esRobot(int tipo) {
    return esUnidad(tipo) && tipo<= FIN_ROBOTS;
}

bool CodigosPaquete::esVehiculo(int tipo) {
    return esUnidad(tipo) && tipo>=COMIENZO_TANQUES;
}

bool CodigosPaquete::esBala(int tipo) {
    return tipo >= bala;
}

std::string CodigosPaquete::nombreUnidad(int tipo) {
    switch (tipo){
        case fuerte:return "Fuerte";
        case fabricaRobot:return "Fábrica Robot";
        case fabricaVehiculo:return "Fábrica Vehículo";
        case grunt:return "Grunt";
        case psycho:return "Psychos";
        case tough:return "Tough";
        case pyro:return "Pyros";
        case sniper:return "Sniper";
        case laser:return "Laser";
        case jeep:return "Jeep";
        case light:return "Light";
        case medium:return "Medium";
        case heavy:return "Heavy";
        case missile:return "Missile";
    }
}
