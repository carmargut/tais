#include <iostream>
#include <fstream>
#include "GrafoDirigido.h"




bool casoDePrueba(){

	int n, // dimensión del tablero
		k, // caras del dado
		s, // serpientes
		e, // escaleras
		vertices;

	std::cin >> n >> k >> s >> e;	
	if (n == 0) return false;

	std::vector<int> fin_atajo(n*n+1, -1);
	vertices = (n*n + 1);
	GrafoDirigido grafo(vertices);
	for (int i = 0; i < s+e; i++){//serpientes y escaleras
		int v, w;
		std::cin >> v >> w;
		fin_atajo[v] = w;
	}
	for (int i = 1; i <= n*n; i++){//paso de casilla en casilla
		for (int j = 1; j <= k; j++){
			int extremo = i + j;
			if ( extremo <= n*n){
				if (fin_atajo[extremo] != -1)
					grafo.ponArista(i, fin_atajo[extremo]);
				else
					grafo.ponArista(i, extremo);
			}

		}
	}
	//________________________________________
	


	BreadthFirstDirectedPaths bfs(grafo, 1);
	if (grafo.E() == 0)
		std::cout << "1" << std::endl;
	else
		std::cout << bfs.distance(n*n) << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (casoDePrueba());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);   //reset to standard input again
	system("PAUSE");
#endif

	return 0;
}
