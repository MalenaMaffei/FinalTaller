/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.h
 * Author: usuario
 *
 * Created on 29 de mayo de 2017, 10:00
 */

#ifndef JUEGO_H
#define JUEGO_H

#include "ManejadorIDs.h"
#include "FabricaInmovibles.h"
#include "FabricaEdificios.h"
#include "FabricaUnidades.h"
#include "server_FabricaMuniciones.h"
#include "server_Mapa.h"
#include "server_Movible.h"
#include "server_Inmovible.h"
#include <vector>
#include <map>
#include "common_Socket.h"
#include "common_Thread.h"
#include <queue>
#include <mutex>
#include <condition_variable>
#include <pthread.h>
#include "server_Jugador.h"
#include "ColaMensajes.h"
#include "server_BoolProtected.h"
#include <tinyxml2.h>

class Juego : public Thread {
public:
    Juego(ColaMensajes& colaDeRecibidos, std::vector<Jugador*>& jugadores);
    void moverUnidades();
    void finalizar();
    bool yaFinalizo();
    bool hayGanador();
    void chequearColisiones();
    void eliminarMuertos();
    void actualizarDisparos();
    void actualizarEdificios();
    void actualizarRecibidos();
    void enviarMensajesEncolados();
    void run();
    virtual ~Juego();
private:
    void inicializarJuego(const std::string& nombreArchivo);
    void inicializarEdificios(int tipo, tinyxml2::XMLElement* padre, 
                                std::string nombreXML);
    void inicializarInmovibles(int tipo, tinyxml2::XMLElement* padre, 
                                std::string nombreXML, std::string nombreObjetos);
    void recibirMover(std::string mensaje);
    void recibirDisparar(std::string mensaje);
    void recibirObtenerInfo(std::string mensaje, int src);
    void recibirCrear(std::string mensaje);    

    void enviarMensaje(Mensaje& mensaje);
    void enviarInfoFabrica(std::string id, int dst);
    void enviarInfoUnidad(std::string id, int dst);
    
    void eliminarPerdedores(int equipoPerdedor);
    
    Mapa mapa;

    BoolProtected finalizado;
    
    ColaMensajes& colaDeRecibidos;
    ColaMensajes colaDeEnviados;
    
    std::vector<Jugador*>& jugadores;
    std::vector<Jugador*> perdedores;
    int equiposActivos;
    
    FabricaUnidades* fabricaUnidades;
    FabricaMuniciones* fabricaMuniciones;
    FabricaEdificios* fabricaEdificios;
    FabricaInmovibles* fabricaInmovibles;
        
    std::array<int,4> banderasPorEquipo;

    std::map<std::string,Movible*> movibles; //Robots, vehiculos, balas
    std::map<std::string,Inmovible*> inmovibles; //Bloques, banderas
    std::map<std::string,Edificio*> edificios; //Edificios

    ManejadorIDs manejadorIDs;
    
};

#endif /* JUEGO_H */

