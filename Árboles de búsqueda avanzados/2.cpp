#include <iostream>
#include <fstream>
#include "BinTree.h"


void casoDePrueba();
BinTree<int> readTree();
bool isAVL(const BinTree<int> &tree, int &height, int &maximo, int &minimo);

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
	system("PAUSE");
#endif

	return 0;
}

BinTree<int> readTree(){

	int numero;
	BinTree<int> tree;
	std::cin >> numero;
	
	if (numero > 0){
		auto leftSon = readTree();
		auto rightSon = readTree();
		tree = BinTree<int>(leftSon, numero, rightSon);
	}
	return tree;

}


void casoDePrueba(){
	BinTree<int> tree = readTree();
	int height = 0, mayor = 0, menor = 0;
 	if (isAVL(tree,height,mayor, menor))
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
}
 
bool isAVL(const BinTree<int> &tree, int &height, int &mayor, int &menor){	
	
	int	minimo = 2147483647,
		maximo = 0,
		altura_izquierdo = 0,
		altura_derecho = 0;

	if (tree.empty()){
		height = 0;
		return true;
	}


	if (tree.left().empty()){
		menor = tree.root();
	}
	else{
		if (tree.left().root() >= tree.root()
			|| !isAVL(tree.left(), altura_izquierdo, maximo, menor)
			|| (maximo >= tree.root()))
				return false;
	}

	if (tree.right().empty()){
		mayor = tree.root();
	}
	else{
		if (tree.right().root() <= tree.root()
			|| !isAVL(tree.right(), altura_derecho, mayor, minimo)
			|| minimo <= tree.root())
				return false;
	}
		
	if (altura_izquierdo > altura_derecho)
		height = altura_izquierdo + 1;
	else
		height = altura_derecho + 1;

	return std::abs(altura_izquierdo - altura_derecho) <= 1;
}