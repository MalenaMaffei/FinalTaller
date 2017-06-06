/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EdificioFabricaVehiculo.cpp
 * Author: usuario
 * 
 * Created on 3 de junio de 2017, 21:37
 */

#include "server_EdificioFabricaVehiculo.h"

EdificioFabricaVehiculo::EdificioFabricaVehiculo (int vida, double ancho, 
												  double alto, int idEquipo, 
												  int tipo) : 
													Edificio (vida, ancho, alto,
															idEquipo, tipo) { }


EdificioFabricaVehiculo::~EdificioFabricaVehiculo () { }

