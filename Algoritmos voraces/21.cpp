#include <iostream>
#include <fstream>
#include "PriorityQueue.h"


bool casoDePrueba(){

	int N,solucion = 0;
	std::cin >> N;
	if (!std::cin)
		return false;

	PriorityQueue<int, std::greater<int>> enemigos(N);
	PriorityQueue<int,std::greater<int>> equipos_de_defensa(N);

	for (int i = 0; i < N; i++){
		int enemigo;
		std::cin >> enemigo;
		enemigos.push(enemigo);
	}
	for (int i = 0; i < N; i++){
		int equipo_de_defensa;
		std::cin >> equipo_de_defensa;
		equipos_de_defensa.push(equipo_de_defensa);
	}

	while (!enemigos.empty()){
		int enemigos_en_ciudad = enemigos.top(),
			defensa_para_ciudad = equipos_de_defensa.top();
		if (enemigos_en_ciudad >  defensa_para_ciudad)
			enemigos.pop();
		else {
			solucion++;
			enemigos.pop();
			equipos_de_defensa.pop();
		}
			
	}

	std::cout << solucion << std::endl;
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

