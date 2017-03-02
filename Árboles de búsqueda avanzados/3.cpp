#include <iostream>
#include <fstream>
#include <vector>

#include "TreeMap_AVL.h"

template <typename Clave, typename Valor, typename Comparador = std::less<Clave>>
class TreeMapRango : public TreeMap<Clave, Valor, Comparador> {
public:

	TreeMapRango(Comparador c = Comparador()) : TreeMap<Clave, Valor, Comparador>(c) {};

	std::vector<Clave> rango(Clave const& k1, Clave const& k2) const {

		std::vector<Clave> rango;
		this->rango(k1-1, k2+1, this->raiz, rango);
		return rango;
	}

protected:
	using TreeNode = typename TreeMap<Clave, Valor, Comparador>::TreeNode;
	using Link = TreeNode *;

	void rango(Clave const& k1, Clave const& k2, Link a, std::vector<Clave> & lista) const {

		if (a == nullptr)
			return;

		if (a->iz != nullptr && this->menor(k1, a->cv.clave)){
			rango(k1, k2, a->iz, lista);
		}

		if (this->menor(k1, a->cv.clave) && this->menor(a->cv.clave, k2)){
			lista.push_back(a->cv.clave);
		}


		if (a->dr != nullptr && this->menor(a->cv.clave, k2)){
			rango(k1, k2, a->dr, lista);
		}


	}
};

TreeMapRango<int, int> leerDatos(size_t numero_nodos){

	int clave;
	TreeMapRango<int, int> arbol;

	for (size_t i = 0; i < numero_nodos; i++){
		std::cin >> clave;
		int valor = clave;
		arbol.insert(clave, valor);
	}

	return arbol;
}



bool resuelveCaso(){
	size_t numero_nodos;
	TreeMapRango<int, int> arbol;
	std::cin >> numero_nodos;
	if (numero_nodos > 0){
		arbol = leerDatos(numero_nodos);
	}
	else{
		return false;
	}

	int clave1, clave2;
	std::cin >> clave1 >> clave2;

	std::vector<int> lista = arbol.rango(clave1, clave2);

	if (lista.size() > 0){// si hay elementos
		std::cout << lista[0];
		for (size_t i = 1; i < lista.size(); i++){
			std::cout << " " << lista[i];
		}
	}
	std::cout << std::endl;
	return true;

}

int main() {

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