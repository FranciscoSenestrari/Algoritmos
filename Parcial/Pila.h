//
// Created by Francisco on 04/04/2016.
//

#ifndef PILAS_PILA_H
#define PILAS_PILA_H

#include "Nodo.h"
#include <string>
template<class T>
class Pila {
private:
    Nodo<T> *nodoTop;

public:
    Pila();

    Pila(T d);

    bool esVacia();

    void push(T);
    T pop(int *e);

    T pop();
    T Peek();
 // void  compare(Pila p2,int e);
    ~Pila();

    T Top();

    int CantE();
};


#endif //PILAS_PILA_H
