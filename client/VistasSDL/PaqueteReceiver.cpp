#include "Header Files/PaqueteReceiver.h"
#include <string>
#include <chrono>
PaqueteReceiver::PaqueteReceiver(const Socket &socket, ColaPaquetes &cola)
    : PaqueteDelivery(socket, cola) {}

void PaqueteReceiver::run() {


    while (!salir){

        int espera = 200;
        Paquete p1, p2, p3, p4, p5, p6;
        p1.setMensaje("0001010101010902");
        p2.setMensaje("0010014001400900");
//        p3.setMensaje("0002000000600000");
//        p4.setMensaje("0003008000000100");
//        p5.setMensaje("0004020002000310");
//        p6.setMensaje("0005040004000300");

        cola.encolar(p1);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(p2);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        cola.encolar(p3);
//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        cola.encolar(p4);
//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        cola.encolar(p5);
//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        cola.encolar(p6);
//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));

        Paquete m1, m2, m3, m4, m5, m6, m3bis;
        m1.setMensaje("200101050101");
        m2.setMensaje("200101100101");
        m3.setMensaje("200101100106");
//
        m4.setMensaje("201001450145");
        m5.setMensaje("201001500150");
        m6.setMensaje("201001550155");

        m3bis.setMensaje("200101100111");
//
//
        cola.encolar(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(m2);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(m3);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(m3bis);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(m4);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(m5);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
        cola.encolar(m6);
        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//
//
        Paquete muerte;
        muerte.setMensaje("1001");
        cola.encolar(muerte);

//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        Paquete bandera;
//        bandera.setMensaje("005000010001020");
//        cola.encolar(bandera);
////
////
//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        bandera.setMensaje("005100500001021");
//        cola.encolar(bandera);
//        std::this_thread::sleep_for(std::chrono::milliseconds(espera));
//        bandera.setMensaje("005201000001022");
//        cola.encolar(bandera);
        salir = true;

//        string mensaje;
//		printf("recibir\n");
//        mensaje = socket.ReceiveStrWLen();
//		printf("paquete %s\n", mensaje.c_str());
//        Paquete paquete;
//		paquete.setMensaje(mensaje);
//		if (paquete.getComando() == 5 || paquete.getComando() == 6){
//			continue;
//
//		}
//        paquete.setMensaje(mensaje);
//        cola.encolar(paquete);
    }
}
