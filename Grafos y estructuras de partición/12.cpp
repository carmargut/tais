#include <iostream>
#include <fstream>
#include "GrafoDirigido.h"
#include "arborescencia.h"


bool casoDePrueba(){
	int V, A, v, w;

	std::cin >> V >> A;

	if (!std::cin)
		return false;

	GrafoDirigido grafo(V);

	while (A--){
		std::cin >> v >> w;
		grafo.ponArista(v, w);
	}

	Arborescencia arborescencia(grafo);

	if (arborescencia.getRaiz() >= 0)
		std::cout << "SI " << arborescencia.getRaiz() << std::endl;
	else
		std::cout << "NO" << std::endl;
	
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while(casoDePrueba());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);   //reset to standard input again
	system("PAUSE");
#endif

	return 0;
}
