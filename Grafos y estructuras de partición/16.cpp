#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"

class PrimMST{
private:

	std::vector<bool> marked;
	std::queue<Arista<int>> mst;
	PriorityQueue<Arista<int>> pq;

public:
	
	PrimMST(const GrafoValorado<int> &grafo){
		
		pq = PriorityQueue<Arista<int>>();
		mst = std::queue<Arista<int>>();
		marked = std::vector<bool>(grafo.V());
		visit(grafo, 0);

		while (!pq.empty() && mst.size() < grafo.V() - 1){
			Arista<int> e = pq.top();
			pq.pop();
			int v = e.uno(), w = e.otro(v);
			if (marked[v] && marked[w]) continue;
			mst.push(e);
			if (!marked[v]) visit(grafo, v);
			if (!marked[w]) visit(grafo, w);
		}


	}

	void visit(const GrafoValorado<int>& grafo, int v){
		marked[v] = true;
		for (Arista<int> e : grafo.adj(v)){
			if (!marked[e.otro(v)])
				pq.push(e);
		}
	}
	
	std::queue<Arista<int>> minimum(){
		return mst;
	}

};


bool pavimentar(const GrafoValorado<int> &grafo,int& coste){
	
	PrimMST prim(grafo);
	std::queue<Arista<int>> mst = prim.minimum();
	if (mst.size() < grafo.V()-1)
		return false;
	else{
		while (!mst.empty()){
			Arista<int> a = mst.front();
			mst.pop();
			coste += a.valor();
		}
	}
	return true;
}

bool casoDePrueba(){

	int INTERSECCIONES, CALLES, coste_pavimentar_todo = 0;

	std::cin >> INTERSECCIONES >> CALLES;
	if (!std::cin) return false;

	GrafoValorado<int> grafo(INTERSECCIONES);

	for (int i = 0; i < CALLES; i++){
		int interseccion_1, interseccion_2, coste_pavimentacion;
		std::cin >> interseccion_1 >> interseccion_2 >> coste_pavimentacion;
		Arista<int> arista(interseccion_1-1, interseccion_2-1, coste_pavimentacion);
		grafo.ponArista(arista);
	}

	if (pavimentar(grafo,coste_pavimentar_todo))
		std::cout << coste_pavimentar_todo << std::endl;
	else
		std::cout << "Imposible" << std::endl;

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
