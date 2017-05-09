#ifndef AEstrella_H_
#define AEstrella_H_

typedef std::tuple<unsigned int, unsigned int> punto; //es mejor hacer clase punto o vertice

class AEstrella {
	private:
		std::vector<std::vector<int>> &mapa;  //tiene que ser un grafo?
		punto &origen; 
		punto &destino;
		vector<punto> listaAbierta;
		vector<punto> listaCerrada;
		std::stack<punto> pila;

	public:


#endif /* AEstrella_H_ */