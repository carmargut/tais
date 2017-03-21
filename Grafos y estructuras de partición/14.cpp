#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "Matriz.h"

bool casoDePrueba(){

	int f, c,actual,encima,izquierda;
	std::cin >> f >> c;
	if (!std::cin) return false;

	Matriz<bool> manchas(f+1,c+1,false);
	std::vector<bool> manchado((f + 1)*(c + 1), false);
	Grafo grafo((f+1)*(c+1));
	char l;
	std::cin.get(l);
	
	for (int fila = 1; fila < f+1; fila++){
		for (int columna = 1; columna < c + 1; columna++){
		
			std::cin.get(l);
			if (l == '#'){
				manchas[fila][columna] = true;
				manchado[(fila-1)*c + columna] = true;

				if (manchas[fila-1][columna]){ // se une con el de arriba
					actual = (fila - 1)*c + columna;
					encima = (fila - 2)*c + columna;
					grafo.ponArista(actual , encima);
				}
				if (manchas[fila][columna-1]){ // se une con el de la izquierda
					actual = (fila - 1)*c + columna;
					izquierda = (fila - 1)*c + columna-1;
					grafo.ponArista(actual,izquierda);
				}
			}
			
		}
		std::cin.get(l);
	}

	ComponentesConexas conex(grafo);

	int maximo = 0;
	for (size_t i = 1; i < grafo.V(); i++){
		int tamano = conex.size(i),fila_n,columna_n;
		fila_n = (i / c) + 1;
		columna_n = i - (fila_n - 1)*c;
		
		if (tamano > maximo && manchado[i])
			maximo = tamano;
	}
	std::cout << maximo << std::endl;
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
