/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   server_constants.h
 * Author: usuario
 *
 * Created on 3 de junio de 2017, 11:49
 */

#ifndef SERVER_CONSTANTS_H
#define SERVER_CONSTANTS_H

#define TICKS 30    //per second
#define CYCLE_TIME (1.0/TICKS) //in seconds
#define NANO 1000000000ULL

#define SIN_EQUIPO 4

#define NUM_EQUIPOS 4

#define TODOS -1	//Si el mensaje estará destino a todos los clientes
#define ESCALA 100	//Al enviar las posiciones al cliente se envian con 
                        //coordenadas enteras, para no perder totalmente la	
                        //precisión se multiplican los double por 100.

enum equipos {
	equipo_1,
	equipo_2,
	equipo_3,
	equipo_4
};

enum largos {
	largoComando = 1,
	largoId = 3,
	largoX = 5,
	largoY = 5,
	largoDelCliente = 1,
	largoTipo = 2,
	largoColor = 1,
	largoEquipo = 1,
	largoVida = 3,
	largoConstrucciones = 2
};

enum comandos {
	comandoCrear = '0',
	comandoMatar = '1',
	comandoMover = '2',
	comandoDisparar = '3',
	comandoInfo = '4',
	comandoInfoUnidad = '4',
	comandoMapa = '5',
	comandoEquipo = '6',
	comandoInfoFabrica = '7',
	comandoDesconectar = '8',
        comandoPerdedor = '9'
};


#endif /* SERVER_CONSTANTS_H */

