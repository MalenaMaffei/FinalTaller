
#ifndef SERVER_CONSTANTS_H
#define SERVER_CONSTANTS_H

/*****************************************************************************/
/* Constantes de tiempos de TICKS                                            */
/*****************************************************************************/

#define TICKS 30    //per second
#define CYCLE_TIME (1.0/TICKS) //in seconds
#define NANO 1000000000ULL

/*****************************************************************************/
/* Constnates  de equipos                                                    */
/*****************************************************************************/

#define NUM_EQUIPOS 4   //Cantidad máxima de equipos posibles en el juego
#define SIN_EQUIPO 4    //Identificador usado para los objetos que no tienen un
                        //equipo 

enum equipos {
	equipo_1,
	equipo_2,
	equipo_3,
	equipo_4
};

/*****************************************************************************/
/* Constantes asociados a los mensajes intercambiados                        */
/*****************************************************************************/

#define TODOS -1	//Si el mensaje estará destino a todos los clientes
#define ESCALA 100	//Al enviar las posiciones al cliente se envian con 
                        //coordenadas enteras, para no perder totalmente la	
                        //precisión se multiplican los double por 100.


/* Largo de cada uno de los campos
 */
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

/* Comando identificador de cada tipo de mensaje
 */
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
        comandoPerdedor = '8',
        comandoGanador = '9',
        comandoDesconectar = 'q' // Mensaje interno en casa de ser necesario 
                                 // desconectar a todos los clientes
};


#endif /* SERVER_CONSTANTS_H */

