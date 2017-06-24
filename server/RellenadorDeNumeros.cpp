/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RellenadorDeNumeros.cpp
 * Author: usuario
 * 
 * Created on 24 de junio de 2017, 15:19
 */

#include "RellenadorDeNumeros.h"

RellenadorDeNumeros::RellenadorDeNumeros () { }

std::string RellenadorDeNumeros::rellenar(int n, int len) {
  	std::string nStr = std::to_string(n);
	int lenN = nStr.size();
	for (int i=0;i<(len-lenN);i++) {
		nStr.insert (0,"0");
	}  
	return nStr;
}

RellenadorDeNumeros::~RellenadorDeNumeros () { }

