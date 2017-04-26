#include <iostream>
#include <fstream>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class Dijkstra{
private:

	std::vector<unsigned long int> distTo;
	std::vector<int> cuantos_caminos_a;
	IndexPQ<int> pq;

public:

	Dijkstra(const GrafoDirigidoValorado<int> &grafo, int s): pq(grafo.V()){
		
		distTo = std::vector<unsigned long int>(grafo.V(), 4294967295);
		cuantos_caminos_a = std::vector<int>(grafo.V(),0);
		distTo[s] = 0;
		cuantos_caminos_a[s] = 1;
		pq.push(s,0);
		
		while (!pq.empty()){
			int v = pq.top().elem;
			pq.pop();
			for (AristaDirigida<int> e : grafo.adj(v))
				relax(e);
		}
	}
	void relax(const AristaDirigida<int> &e){
		int v = e.from(), w = e.to();
		if (distTo[w] > distTo[v] + e.valor()){
			distTo[w] = distTo[v] + e.valor();
			
			cuantos_caminos_a[w] = cuantos_caminos_a[v];
			pq.update(w, distTo[w]);
						
		}
		else if (distTo[w] == distTo[v] + e.valor()){
			cuantos_caminos_a[w] += cuantos_caminos_a[v];
		}
	}

	int vias_posibles(int v){
		return cuantos_caminos_a[v];
	}

};

bool casoDePrueba(){

	int INTERSECCIONES, CALLES;
	std::cin >> INTERSECCIONES >> CALLES;
	if (!std::cin) { return false; }
	GrafoDirigidoValorado<int> grafo(INTERSECCIONES+1);

	for (int calle = 0; calle < CALLES; calle++){
		int calle1, calle2, valor;
		std::cin >> calle1 >> calle2 >> valor;
		AristaDirigida<int> arista(calle1, calle2, valor);
		AristaDirigida<int> inversa(calle2, calle1, valor);
		grafo.ponArista(arista);
		grafo.ponArista(inversa);
	}

	Dijkstra d(grafo, 1);
	std::cout << d.vias_posibles(INTERSECCIONES) << std::endl;

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

