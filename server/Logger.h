/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Logger.h
 * Author: usuario
 *
 * Created on 26 de junio de 2017, 00:55
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <mutex>

class Logger {
public:
    static Logger* getInstancia();
    void logACout(const std::string& mensaje);
    void logACerr(const std::string& mensaje);
    virtual ~Logger();
private:
    static Logger* instancia;
    std::mutex coutMutex;
    std::mutex cerrMutex;
};

#endif /* LOGGER_H */

