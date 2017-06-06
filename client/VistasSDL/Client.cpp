#include "Header Files/Canvas.h"
#include "Header Files/PaqueteReceiver.h"
#include "Header Files/PaqueteSender.h"

int main (int argc, char *argv[]){

    printf("probando thread\n");
    ColaPaquetes colaEntrada;
    ColaPaquetes colaSalida;

//    DESCOMENTAR PARA PROBAR CON SERVER
    Socket socket;
//    socket.setClientMode(argv[1], argv[2]);

    Paquete p1, p2, p3, p4, p5, p6;
    p1.setMensaje("0001000100010910");
    p2.setMensaje("0010004000400900");
    p3.setMensaje("0002000000600000");
    p4.setMensaje("0003008000000100");
    p5.setMensaje("0004020002000310");
    p6.setMensaje("0005040004000300");
    colaEntrada.encolar(p1);
    colaEntrada.encolar(p2);
    colaEntrada.encolar(p3);
    colaEntrada.encolar(p4);
    colaEntrada.encolar(p5);
    colaEntrada.encolar(p6);

    PaqueteReceiver receiver(socket, colaEntrada);
    PaqueteSender sender(socket, colaSalida);


    Canvas canvas(colaEntrada, colaSalida);

    canvas.start();
    receiver.start();
    sender.start();
    canvas.join();
//   TODO FALTA CONDICION DE QUIT!
}
