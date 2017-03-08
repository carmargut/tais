#include <iostream>
#include <fstream>
#include "Grafo.h"


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

	 
	 BreadthFirstPaths bfs(grafo, 0);
	 bool esLibre = true;

	for (auto i = 0; i < grafo.V(); i++){
		if (!bfs.hasPathTo(i)){
			esLibre = false;
		}
	}
	if (grafo.E() != grafo.V() - 1)
		esLibre = false;

	if (esLibre)
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
