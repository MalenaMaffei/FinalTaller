/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Logger.cpp
 * Author: usuario
 * 
 * Created on 26 de junio de 2017, 00:55
 */

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

