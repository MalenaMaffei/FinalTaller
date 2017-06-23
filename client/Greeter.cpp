#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Header Files/Greeter.h"
#include "Header Files/constantes.h"
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT "8080"
using std::string;
void Greeter::greet() {
    std::ifstream inFile;
    inFile.open(greeterPath);
    std::string linea;
    while (getline(inFile, linea)){
        std::cout << linea <<std::endl;
    }

    inFile.close();
}

std::string Greeter::pedirIp() {
    string input = "";
    std::cout << "\nIngrese la dirección IP [default "<< DEFAULT_IP"]:\n> ";
    getline(std::cin, input);
    if (input.empty()){
        return DEFAULT_IP;
    }
    return input;
}

std::string Greeter::pedirPuerto() {
    string input = "";
    std::cout << "Ingrese el puerto [default "<< DEFAULT_PORT"]:\n> ";
    getline(std::cin, input);
    if (input.empty()){
        return DEFAULT_PORT;
    }
    return input;
}
