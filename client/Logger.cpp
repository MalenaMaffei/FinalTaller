#include <iostream>
#include <string>
#include "Header Files/Logger.h"
Logger* Logger::instancia = NULL;

Logger* Logger::getInstancia() {
  if (!instancia) {
    instancia = new Logger();
  }
  return instancia;
}

void Logger::deleteInstancia() {
  if (!instancia) {
    return;
  }
  delete instancia;
  instancia = NULL;
}

void Logger::logACout(const std::string& mensaje) {
  std::unique_lock<std::mutex> mlock(coutMutex);
  std::cout<<mensaje<<std::endl;
}

void Logger::logACerr(const std::string& mensaje) {
  std::unique_lock<std::mutex> mlock(coutMutex);
  std::cout<<mensaje<<std::endl;
}

Logger::~Logger() { }
