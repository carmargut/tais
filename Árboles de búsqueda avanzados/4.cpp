

#include <iostream>
#include <fstream>

#include "TreeMap_AVL_tami.h"

bool casoDePrueba();

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

bool casoDePrueba(){

	TreeMap<int, int> arbol;

	int nClaves, clave, elementosAConsultar, posicion;
	
	std::cin >> nClaves;
	if (nClaves == 0)
		return false;

	for (auto i = 0; i < nClaves; i++){
		
		std::cin >> clave;
		arbol.insert(clave, 0);
	}
	std::cin >> elementosAConsultar;

	for (auto  i = 0; i < elementosAConsultar; i++){
		std::cin >> posicion;
		clave = arbol.k_esimo(posicion);
		
		if (clave == -1)
			std::cout << "??" << std::endl;
		else
			std::cout << clave << std::endl;
	}
	std::cout << "----" << std::endl;

	return true;
}