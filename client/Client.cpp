#include "Header Files/Canvas.h"
#include "Header Files/PaqueteReceiver.h"
#include "Header Files/PaqueteSender.h"

int main(int argc, char *argv[]){
    printf("probando thread\n");
    ColaPaquetes colaEntrada;
    ColaPaquetes colaSalida;

//    DESCOMENTAR PARA PROBAR CON SERVER
    Socket socket;
    socket.setClientMode(argv[1], argv[2]);



    PaqueteReceiver receiver(socket, colaEntrada);
    PaqueteSender sender(socket, colaSalida);


    Canvas canvas(colaEntrada, colaSalida);

    canvas.start();
    receiver.start();
    sender.start();
    canvas.join();
//   TODO FALTA CONDICION DE QUIT!
}
