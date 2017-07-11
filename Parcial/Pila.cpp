//
// Created by Francisco on 04/04/2016.
//


#include <iostream>
using namespace std;
#include "Pila.h"

template<class T>
Pila<T>::Pila() {
    nodoTop = NULL;
}

template<class T>
Pila<T>::Pila(T d) {
    nodoTop = new Nodo<T>(d);
}

template<class T>
bool Pila<T>::esVacia() {
    return nodoTop == NULL;
}

template<class T>
void Pila<T>::push(T d) {
    Nodo<T> *newNodo = new Nodo<T>(d);
    newNodo->setNext(nodoTop);
    nodoTop = newNodo;
}

template<class T>
T Pila<T>::pop(int *e) {
    Nodo<T> *nodoTmp;
    T v;

    nodoTmp = nodoTop;
    if (esVacia()) {
        *e = 1;
        return 0;
    }

    nodoTop = nodoTop->getNext();
    v = nodoTmp->getDato();
    delete (nodoTmp);

    *e = 0;
    return v;
}

template<class T>
T Pila<T>::pop() {
    int err;
    return pop(&err);
}

template<class T>
Pila<T>::~Pila() {
    int e;
    while (!esVacia()) {
        pop(&e);
    }
}
template<class T>
int  Pila<T>::CantE() {

    int n=0;
    while(this->esVacia()==NULL)
    {
        n++;
    }

return n;
}
template<class T>
T Pila<T>::Top() {
    return this->nodoTop->getDato();

}
template<class T>
T Pila<T>::Peek() {
    T aux;
    aux=this->pop();
    this->push(aux);
    return aux;
}
/*template <class T>
void  Pila::/compare( Pila p2,int  e)
{

    T *a,*b;
    a = new T[e];
    b = new T[e];
    for (int i = 0; i < e; ++i)
    {

        a[i]=this->pop;
        b[i]= p2.pop();

    }
    for (int j = 0; j < e; ++j)
    {
        if  (a[j]== b[j])
        {
            cout << '✓';
        }
        else
            cout<<"x";
    }


}
*/

template
class Pila<float>;

template
class Pila<char>;

template
class Pila<int>;

template
class Pila<double>;

template
class Pila<string>;


