
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

