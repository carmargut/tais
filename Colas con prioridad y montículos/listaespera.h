
#ifndef LISTAESPERA_H
#define LISTAESPERA_H


#include <string>
#include "PriorityQueue.h"


class ListaEspera{



private:

	struct Paciente{
		std::string nombre;
		int gravedad;
		int orden_llegada;
	};

	class Comparador{
	public:
		bool operator()(Paciente p1,Paciente p2){
			return p1.gravedad > p2.gravedad || (p1.gravedad == p2.gravedad && p1.orden_llegada < p2.orden_llegada);
		}
	};

	PriorityQueue<Paciente, Comparador> lista;
	int orden;


public:

	ListaEspera(int t = TAM_INICIAL) : lista(t), orden(0){};

	void ingresarPaciente(std::string nombre, int gravedad){
		lista.push({ nombre, gravedad, orden++ });
	}

	std::string nombrePrimero(){
		return lista.top().nombre;
	}

	void atenderPaciente(){
		lista.pop();
	}
	
};



#endif