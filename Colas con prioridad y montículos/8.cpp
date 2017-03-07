#include <iostream>
#include <fstream>
#include "listaespera.h"


typedef struct{ 
	char nombre[20];
	int tiempo;
} tPersona;





bool casoDePrueba(){
	
	ListaEspera listaPacientes;
	int numero_eventos, gravedad;
	std::string nombre;

	std::cin >> numero_eventos;
	if (numero_eventos == 0)
		return false;

	for (int i = 0; i < numero_eventos; i++){
		char tipo_evento;
		std::cin >> tipo_evento;
		switch (tipo_evento){
		case 'I':
			std::cin >> nombre >> gravedad;
			listaPacientes.ingresarPaciente(nombre, gravedad);
			break;
		case 'A':
			std::cout << listaPacientes.nombrePrimero() << std::endl;
			listaPacientes.atenderPaciente();
		default:
			break;
		}

	}
	std::cout << "----" << std::endl;

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