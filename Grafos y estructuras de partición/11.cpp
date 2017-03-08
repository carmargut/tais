#include <iostream>
#include <fstream>
#include "Grafo.h"

typedef enum{
	naranja,
	azul,
	no_coloreado
} color;

bool esAzulYBipartito(const Grafo &grafo, int v, std::vector<color>& coloreado);


bool esNaranjaYBipartito(const Grafo &grafo, int v, std::vector<color>& coloreado){


	coloreado[v] = naranja;
	for (int w : grafo.adj(v)){
		if (coloreado[w] != azul){
			if (coloreado[w] == naranja || !esAzulYBipartito(grafo, w,coloreado))
				return false;
		}		
	}
	return true;
}

bool esAzulYBipartito(const Grafo &grafo, int v, std::vector<color>& coloreado){

	coloreado[v] = azul;
	for (int w : grafo.adj(v)){
		if (coloreado[w] != naranja){
			if (coloreado[w] == azul || !esNaranjaYBipartito(grafo, w, coloreado))
				return false;
		}
		
	}
	return true;
}

bool esBipartito(const Grafo &grafo){

	std::vector<color> coloreado(grafo.V(), no_coloreado);
	bool bipartito = true;
	// colorearemos el grafo en dos colores: azul y naranja
	for (int i = 0; i < grafo.V() && bipartito; i++){
		if(coloreado[i] == no_coloreado)
			bipartito = esAzulYBipartito(grafo, i, coloreado);
	}

	return bipartito;
}

bool resuelveCaso(){
	int V, A, v, w;
	std::cin >> V; // número de vértices
	if (!std::cin)  // hemos terminado de procesar todos los casos
		return false;
	std::cin >> A; // número de aristas
	Grafo grafo(V);
	// leemos las aristas
	for (int i = 0; i < A; ++i) {
		std::cin >> v >> w;
		grafo.ponArista(v, w);
	}


	bool es_bipartito = esBipartito(grafo);

	if (es_bipartito)
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;

	return true;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);   //reset to standard input again
	system("PAUSE");
#endif

	return 0;
}
