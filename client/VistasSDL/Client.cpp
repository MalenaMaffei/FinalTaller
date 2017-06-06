#include "Header Files/Canvas.h"

int main (){

    printf("probando thread\n");
    ColaPaquetes colaEntrada;
    ColaPaquetes colaSalida;
    Canvas canvas(colaEntrada, colaSalida);

    canvas.start();
    canvas.join();
}
