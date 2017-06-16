#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Header Files/Greeter.h"
#include "Header Files/constantes.h"
void Greeter::greet() {
    std::ifstream inFile;
    inFile.open(greeterPath);
    std::string linea;
    while (getline(inFile, linea)){
        std::cout << linea <<std::endl;
    }

    inFile.close();
}
