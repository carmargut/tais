#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "Matriz.h"
#include "ConjuntosDisjuntos15.h"

void introducePixel(ConjuntosDisjuntos15 &conjunto, Matriz<bool> &manchas, int FILAS, int COLUMNAS,int& maximo){

	int columna_pixel_nuevo, fila_pixel_nuevo;
	std::cin >> fila_pixel_nuevo >> columna_pixel_nuevo;

	int actual = (fila_pixel_nuevo - 1)*COLUMNAS + columna_pixel_nuevo,
		encima = (fila_pixel_nuevo - 2)*COLUMNAS + columna_pixel_nuevo,
		debajo = (fila_pixel_nuevo)*COLUMNAS + columna_pixel_nuevo,
		derecha = actual + 1,
		izquierda = actual - 1;

	manchas[fila_pixel_nuevo][columna_pixel_nuevo] = true;
	


	if (manchas[fila_pixel_nuevo - 1][columna_pixel_nuevo]){ // se une con el de arriba
		conjunto.unir(actual, encima);
	}
	if (fila_pixel_nuevo != FILAS && manchas[fila_pixel_nuevo + 1][columna_pixel_nuevo]){ // se une con el de debajo
		conjunto.unir(actual, debajo);
	}
	if (manchas[fila_pixel_nuevo][columna_pixel_nuevo - 1]){ // se une con el de la izquierda
		conjunto.unir(actual, izquierda);
	}
	if (columna_pixel_nuevo != COLUMNAS && manchas[fila_pixel_nuevo][columna_pixel_nuevo + 1]){ // se une con el de la derecha
		conjunto.unir(actual, derecha);
	}

	int tamano = conjunto.tamano(actual);
	if (tamano > maximo)
			maximo = tamano;
	
	std::cout << maximo;
}

bool casoDePrueba(){

	int f, c, actual, encima, izquierda,n_manchas_nuevas;
	std::cin >> f >> c;
	if (!std::cin) return false;

	Matriz<bool> manchas(f + 1, c + 1, false);
	ConjuntosDisjuntos15 conjunto((f + 1)*(c + 1));
	char l;
	std::cin.get(l);
	int maximo = 0,tamano;

	for (int fila = 1; fila < f + 1; fila++){
		for (int columna = 1; columna < c + 1; columna++){

			std::cin.get(l);
			if (l == '#'){
				manchas[fila][columna] = true;

				if (manchas[fila - 1][columna]){ // se une con el de arriba
					actual = (fila - 1)*c + columna;
					encima = (fila - 2)*c + columna;
					conjunto.unir(actual, encima);
				    tamano = conjunto.tamano(actual);
					if (tamano > maximo)
						maximo = tamano;
				}
				if (manchas[fila][columna - 1]){ // se une con el de la izquierda
					actual = (fila - 1)*c + columna;
					izquierda = (fila - 1)*c + columna - 1;
					conjunto.unir(actual, izquierda);
					tamano = conjunto.tamano(actual);
					if (tamano > maximo)
						maximo = tamano;
				}
			}

		}
		std::cin.get(l);
	}

	std::cin >> n_manchas_nuevas;
	
	for (int i=0; i < n_manchas_nuevas; ++i){
		if (i) std::cout << " ";
		introducePixel(conjunto, manchas, f, c, maximo);
	}
	std::cout << "\n";

	/*while (n_manchas_nuevas--){
		introducePixel(conjunto, manchas,f,c,maximo);
		if (n_manchas_nuevas)
			std::cout << " ";
		else
			std::cout << "\n";
	}	*/																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	

	
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
