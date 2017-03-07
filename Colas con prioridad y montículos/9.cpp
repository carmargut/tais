#include <iostream>
#include <fstream>
#include "PriorityQueue.h"


bool casoDePrueba(){
	
	int edad_pajaro, numero_parejas,primer_pajaro;
	PriorityQueue<int, std::greater<int>> pequenos;
	PriorityQueue<int> mayores;

	std::cin >> edad_pajaro >> numero_parejas;

	if (edad_pajaro == 0 && numero_parejas == 0) 
		return false;
	pequenos.push(edad_pajaro);
	mayores.push(edad_pajaro);
	primer_pajaro = edad_pajaro;
	while (numero_parejas--){
		for (size_t i = 0; i < 2; i++){
			std::cin >> edad_pajaro;
			if (edad_pajaro < primer_pajaro)
				pequenos.push(edad_pajaro);
			if (edad_pajaro > primer_pajaro)
				mayores.push(edad_pajaro);
		}
		if (pequenos.size() > mayores.size()){
			pequenos.pop();
			mayores.push(pequenos.top());
			primer_pajaro = pequenos.top();
		}
		else if (pequenos.size() < mayores.size()){
			mayores.pop();
			pequenos.push(mayores.top());
			primer_pajaro = mayores.top();
		}
		std::cout << primer_pajaro;
		if (numero_parejas != 0)
			std::cout << " ";
	}
	std::cout << std::endl;


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