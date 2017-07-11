//
// Created by Francisco on 25/04/2016.
//

#include <iostream>
#include "Lista.h"

using namespace std;

template<class T>
Lista<T>::Lista() {
    primero = NULL;
    tamanio = 0;
}

template<class T>
Lista<T>::Lista(T d) {
    primero = new Nodo<T>(d);
    tamanio = 1;
}

template<class T>
void Lista<T>::insertarEn(int pos, T d) {
    Nodo<T> *currNodo = primero, *antNodo = NULL, *newNode;
    int actPos = 0;

    while (currNodo != NULL && actPos < pos) {
        actPos++;
        antNodo = currNodo;             //Uso tmpNodo para guardar el anterior
        currNodo = currNodo->getNext();
    }
    if (actPos == pos) {
        if (antNodo == NULL) {          // Si el anterior es NULL, estoy en el primer elemento
            primero = new Nodo<T>(d);
            primero->setNext(currNodo); // currNodo tiene el puntero a primero.
        }else{
            newNode = new Nodo<T>(d);
            newNode->setNext(currNodo);
            antNodo->setNext(newNode);
        }
        tamanio++;
    }
}

template<class T>
int Lista<T>::getTamanio() {
    int actPos = 0;
    Nodo<T> *currNodo = primero;
    while (currNodo != NULL) {
        actPos++;
        currNodo = currNodo->getNext();
    }
    return actPos;
}

template<class T>
void Lista<T>::insertarFin(T d) {
    insertarEn(getTamanio(), d);
}

template<class T>
void Lista<T>::insertarPrincipio(T d) {
    insertarEn(0, d);
}

template<class T>
int Lista<T>::buscar(T d) {
    return 0;
}

template<class T>
int Lista<T>::eliminar(int pos) {
    int actPos = 0;
    Nodo<T> *currNodo = primero, *antNodo = NULL;

    if(esVacio())
        return -2;

    while (currNodo != NULL && actPos < pos) {
        actPos++;
        antNodo = currNodo;
        currNodo = currNodo->getNext();
    }

    if (actPos == pos && currNodo != NULL) {
        if (antNodo != NULL) {
            antNodo->setNext(currNodo->getNext());
        }
        delete (currNodo);
        tamanio--;
        return 0;
    }
    return -1;
}

template<class T>
Lista<T>::~Lista() {
    Nodo<T> *currNodo = primero, *tmpNodo;
    while (currNodo != NULL) {
        tmpNodo = currNodo;
        currNodo = currNodo->getNext();
        delete (tmpNodo);
    }
}

template<class T>
void Lista<T>::imprimir() {
    Nodo<T> *currNodo = primero;
    while (currNodo != NULL) {
        cout << currNodo->getDato() << " -> ";
        currNodo = currNodo->getNext();
    }
    cout << "\n";
}

template<class T>
T Lista<T>::getDato(int pos, int *err) {
    int actPos = 0;
    Nodo<T> *currNodo = primero;
    while (currNodo != NULL && actPos < pos) {
        actPos++;
        currNodo = currNodo->getNext();
    }

    if (actPos == pos && currNodo !=NULL) {
        *err = 0;
        return currNodo->getDato();
    }
    *err = 1;
    return 0;
}

template<class T>
T Lista<T>::getDato(int pos){
    int tmp;
    return getDato(pos,&tmp);
}

template<class T>
int Lista<T>::setDato(int pos, T d) {
    int actPos = 0;
    Nodo<T> *currNodo = primero;
    while (currNodo != NULL && actPos < pos) {
        actPos++;
        currNodo = currNodo->getNext();
    }

    if (actPos == pos && currNodo !=NULL){
        currNodo->setDato(d);
        return 0;
    }
    return 1;
}


template
class Lista<float>;

template
class Lista<char>;

template
class Lista<int>;

template
class Lista<double>;