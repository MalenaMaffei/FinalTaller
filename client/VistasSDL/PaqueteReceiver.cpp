#include "Header Files/PaqueteReceiver.h"
#include <string>
#include <chrono>
PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {


    while (!salir){

        Paquete p1, p2, p3, p4, p5, p6;
        p1.setMensaje("0001000100010910");
        p2.setMensaje("0010004000400900");
        p3.setMensaje("0002000000600000");
        p4.setMensaje("0003008000000100");
        p5.setMensaje("0004020002000310");
        p6.setMensaje("0005040004000300");

        cola.encolar(p1);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(p2);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(p3);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(p4);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(p5);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(p6);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        Paquete m1, m2, m3, m4, m5, m6;
        m1.setMensaje("200100050001");
        m2.setMensaje("200100100001");
        m3.setMensaje("200100100006");

        m4.setMensaje("201000450045");
        m5.setMensaje("201000500050");
        m6.setMensaje("201000550055");


        cola.encolar(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(m2);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(m3);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(m4);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(m5);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cola.encolar(m6);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));


        Paquete muerte;
        muerte.setMensaje("1001");
        cola.encolar(muerte);

        salir = true;

//        string mensaje;
//        mensaje = socket.ReceiveStrWLen();
//        Paquete paquete;
//        paquete.setMensaje(mensaje);
//        cola.encolar(paquete);
    }
}
