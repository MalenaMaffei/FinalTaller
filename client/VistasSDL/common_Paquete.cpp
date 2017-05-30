#include "common_Paquete.h"
#include "ElementoBandera.h"
#include "ElementoRoca.h"
#include "ElementoPuente.h"
#include "ElementoFuerte.h"

using std::string;
using std::stoi;
using std::map;

Paquete::Paquete(std::string mensaje) {
    id = stoi(mensaje.substr(0,3));
    comando = stoi(mensaje.substr(3,1));
    if (comando == matar){
        return ;
    }

    x = stoi(mensaje.substr(4,4));
    y = stoi(mensaje.substr(8,4));

    if (comando == crear){
        esMio = stoi(mensaje.substr(12,1));
        tipo = stoi(mensaje.substr(13,1));
        if (mensaje.size() == 15){
            color = stoi(mensaje.substr(14,1));
        }
    }
}

//void Paquete::aplicar(std::map<int, Vista*> &vistas,
//                      std::map<int, VistaDireccionada*> &vistasDireccionadas,
//                      std::map<int, Elemento*> &elementos,
//                      std::map<int, ElementoUnidad*> &unidades) {
//
//    if(comando == crear){
////        TODO depende el rango
//        if(0 <= comando && comando >= 5){
//            crearElemento(vistas, elementos);
//        } else{
//            crearUnidad(vistas, vistasDireccionadas, elementos, unidades);
//        }
//
//
//    }
//
//
//}
int Paquete::getId() const {
    return id;
}
int Paquete::getComando() const {
    return comando;
}
int Paquete::getX() const {
    return x;
}
int Paquete::getY() const {
    return y;
}
int Paquete::getTipo() const {
    return tipo;
}
bool Paquete::isEsMio() const {
    return esMio;
}
int Paquete::getColor() const {
    return color;
}
//
//void Paquete::crearElemento(map<int, Vista *> &vistas, map<int, Elemento*> &elementos) {
//    Elemento* elemento;
//    switch (tipo){
//        case bandera:{
//            elemento = new ElementoBandera(id, x, y, vistas.at(tipo), color);
//        } break;
//
//        case roca:{
//            elemento = new ElementoRoca(id, x, y, vistas.at(tipo));
//        } break;
//
//        case puente:{
//            elemento = new ElementoPuente(id, x, y, vistas.at(tipo));
//        } break;
//
//        case fuerte:{
//            elemento = new ElementoFuerte(id, x, y, vistas.at(tipo),color);
//        }
//
//    }
////    TODO agregar en el mapa al elemento
//
//}
//void Paquete::crearUnidad(map<int, Vista *> &vistas,
//                          map<int,VistaDireccionada *> &vistasDireccionadas,
//                          map<int, Elemento *> &elementos,
//                          map<int, ElementoUnidad *> &unidades) {
//
//    Elemento* elemento;
//    ElementoUnidad* unidad;
//    switch (tipo){
//        case grunt:{
//            unidad = new ElementoUnidad(id, x, y, vistasDireccionadas.at
//                                            (tipo), vistasDireccionadas.at
//                (tipo), vistas.at(tipo), esMio, color);
//        } break;
//
//        case psycho:{
//
//        } break;
//
//        case tough:{
//
//        } break;
//
//        case pyro:{
//
//        } break;
//
//        case sniper:{
//
//        } break;
//
//        case laser:{
//
//        } break;
//
//        case jeep:{
//
//        } break;
//
//        case light:{
//
//        } break;
//
//        case medium:{
//
//        } break;
//
//        case heavy:{
//
//        } break;
//
//        case missile:{
//
//        } break;
//    }
//
//}


