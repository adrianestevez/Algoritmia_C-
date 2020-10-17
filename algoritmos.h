#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <iostream>
#include <vector>
#include <sstream>
#include "cliente.h"

using namespace std;


template <class T>
class algoritmos
{
public:
    algoritmos();
    void merge(vector<T>& v, int ini, int fin, bool(*mayorQue) (T, T));
    void _mergesort(vector<T>& v, int ini, int fin, bool(*mayorQue)(T, T));
    void ordenar(vector<T>& v, bool(*mayorQue)(T, T));

    bool mayorStockMinimo(Cliente* a, Cliente* b){
        return a->getId() > b->getId();
    }

};

template<class T>
void merge(vector<T>& v, int ini, int fin, bool(*mayorQue) (T, T)){
    int m = (ini + fin) / 2;
    int h = ini;
    int k = m + 1;
    int n = fin - ini + 1;
    T* aux = new T[n];
    int j = 0;

    while (h <= m || k <= fin){
        if (h > m)aux[j++] = v[k++];
        else if (k > fin) aux[j++] = v[h++];
        else if (mayorQue(v[h], v[k])) aux[j++] = v[k++];
        else aux[j++] = v[h++];
    }
    for (int i = 0; i < n; ++i){
        v[ini + i] = aux[i];
    }
    delete[] aux;
}


template<class T>
void _mergesort(vector<T>& v, int ini, int fin, bool(*mayorQue)(T, T)){
    if (ini >= fin) return;
    int m = (ini + fin) / 2;
    _mergesort(v, ini, m, mayorQue);
    _mergesort(v, m + 1, fin, mayorQue);
    merge(v, ini, fin, mayorQue);
}

template<class T>
void ordenar(vector<T>& v, bool(*mayorQue)(T, T)){
    _mergesort(v, 0, v.size() - 1, mayorQue);
}


#endif // ALGORITMOS_H
