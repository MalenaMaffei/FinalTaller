#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Greeter.h"
void Greeter::greet() {
    std::ifstream inFile;
    inFile.open("../client/greeting.txt");
    std::string linea;
    while (getline(inFile, linea)){
        std::cout << linea <<std::endl;
    }

    inFile.close();
}
