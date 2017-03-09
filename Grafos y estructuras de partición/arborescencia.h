
#ifndef ARBORESCENCIA_H
#define ARBORESCENCIA_H

#include "GrafoDirigido.h"

class Arborescencia{
public:

	Arborescencia(const GrafoDirigido &grafo){
		int nodos_visitados = 0,
			v=grafo.V();
		raiz = -1;
		bool salir = false;
		GrafoDirigido inverso = grafo.reverse();
		marcados = std::vector<bool>(v, false);

		for (int i = 0; i < v && !salir; i++){
			if (inverso.adj(i).size() == 0){
				if (raiz == -1){
					nodos_visitados = 1;
					if (dfs(grafo, i, nodos_visitados) && nodos_visitados == v){
						raiz = i;
						salir = true;
					}
				}
				else
					salir = true;
			}
		}
	}

	int getRaiz(){
		return raiz;
	}

private:

	int raiz;
	std::vector<bool> marcados;

	bool dfs(GrafoDirigido const& G, size_t v,int& nodos_visitados) {
		marcados[v] = true;

		for (size_t w : G.adj(v)) {
			if (!marcados[w]) {
				nodos_visitados++;
				if (!dfs(G, w, nodos_visitados))
					return false;
			}
			else
				return false;
		}
		return true;
	}


};



#endif