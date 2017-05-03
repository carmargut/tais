#include <iostream>
#include <fstream>
#include <vector>

bool casoDePrueba(){

	int numero_agujeros, longitud_parches;
	std::cin >> numero_agujeros >> longitud_parches;
	if (!std::cin)
		return false;
	std::vector<int> agujeros(numero_agujeros);
	int parches_gastados = 1;
	

	for (int i = 0; i < numero_agujeros; i++){
		int posicion;
		std::cin >> posicion;
		agujeros[i] = posicion;
	}

	

	int hasta_donde_llega_el_parche = longitud_parches + agujeros[0];

	for (int i = 1; i < numero_agujeros; i++){
		
		if (hasta_donde_llega_el_parche < agujeros[i]){ // el parche no llega
			parches_gastados++;
			hasta_donde_llega_el_parche = longitud_parches + agujeros[i];
		}
		
	}

	std::cout << parches_gastados << std::endl;

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

