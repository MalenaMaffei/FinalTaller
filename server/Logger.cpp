
#include "Logger.h"
#include <iostream>

Logger* Logger::instancia = NULL;

Logger* Logger::getInstancia () {
	if (!instancia) {
		instancia = new Logger();
	}
	return instancia;
}

void Logger::logACout(const std::string& mensaje) {
	std::unique_lock<std::mutex> mlock(coutMutex);
	std::cout<<mensaje<<std::endl;
}

void Logger::logACerr(const std::string& mensaje) {
	std::unique_lock<std::mutex> mlock(coutMutex);
	std::cout<<mensaje<<std::endl;  
}

Logger::~Logger () { }

