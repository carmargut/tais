#include <iostream>
#include <fstream>
#include "BinTree.h"


BinTree<int> leerArbol(){
	
	int nodo;
	std::cin >> nodo;

	if (nodo == -1)
		return{};
	else{
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, nodo, dr };
	}

}

bool esUnMonticuloDeMinimos(const BinTree<int> &arbol,int &alturaMaxima, bool &primeraHojaAlcanzada,int k, bool &desnivelEncontrado){

	

	if (arbol.empty()){
		if (primeraHojaAlcanzada){
			primeraHojaAlcanzada = false;
			alturaMaxima = k - 1;
		}
		else if (k == alturaMaxima && desnivelEncontrado == false){
			desnivelEncontrado = true;
		}
		else if (k < alturaMaxima) // el arbol acaba a un nivel muy inferior
			return false;
	}
	else{
		
		
		if (desnivelEncontrado){ // si estamos en el hueco 
			if (k == alturaMaxima) // pero hay un nodo
				return false;
		}
		else if (k == alturaMaxima + 1)//si nos hemos pasado
			return false;

		if ((!arbol.left().empty() && arbol.left().root() < arbol.root())
			|| (!arbol.right().empty() && arbol.right().root() < arbol.root())) //si los hijos son menores
			return false;

		if (!esUnMonticuloDeMinimos(arbol.left(), alturaMaxima, primeraHojaAlcanzada, k + 1, desnivelEncontrado))
			return false;
		if  (!esUnMonticuloDeMinimos(arbol.right(), alturaMaxima, primeraHojaAlcanzada, k + 1, desnivelEncontrado))
			return false;

	}

	return true;
}

bool esUnMonticuloDeMinimos(const BinTree<int> &arbol){

	int alturaMaxima = -1;
	bool primeraHojaAlcanzada = true,
		 desnivelEncontrado = false;


	return esUnMonticuloDeMinimos(arbol,alturaMaxima, primeraHojaAlcanzada, 1, desnivelEncontrado);
}

void casoDePrueba(){
	
	BinTree<int> arbol = leerArbol();

	if (esUnMonticuloDeMinimos(arbol))
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;

}




int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		casoDePrueba();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);   //reset to standard input again
	//char ch;
	//std::cin >> ch;
	system("PAUSE");
#endif

	return 0;
}

