
#include "ConjuntosDisjuntos15.h"

ConjuntosDisjuntos15::ConjuntosDisjuntos15(size_t N) : size(N), _count(size), id(size, -1) {}

size_t ConjuntosDisjuntos15::buscar(size_t p) const {
    if (id[p] < 0) // es una raíz
        return p;
    else
        return id[p] = int(buscar(id[p]));
}

//devuelve el tamaño del conjunto que contiene a p
size_t ConjuntosDisjuntos15::tamano(size_t p){
	if (id[p] < 0)
		return -id[p];
	else
		return tamano(id[p]);
}

// unir los conjuntos que contengan a p y q
void ConjuntosDisjuntos15::unir(size_t p, size_t q) {
    auto i = buscar(p);
    auto j = buscar(q);
    if (i == j) return;
    if (id[i] < id[j]) { // i es la raíz del mayor árbol
        id[i] += id[j]; id[j] = int(i);  
    } else {
        id[j] += id[i]; id[i] = int(j);
    }
    _count--;
}

// muestra el array por la salida o
void ConjuntosDisjuntos15::print(std::ostream& o) const {
    o << _count << ": ";
    for (size_t i = 0; i < size; ++i)
        o << id[i] << " ";
}


std::ostream& operator<<(std::ostream & o, ConjuntosDisjuntos15 const& a){
    a.print(o);
    return o;
}
