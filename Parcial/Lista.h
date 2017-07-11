//
// Created by Francisco on 25/04/2016.
//

#ifndef TP_LISTAS_LISTA_H
#define TP_LISTAS_LISTA_H


#include <iostream>
#include "Nodo.h"

template<class T>
class Lista {
private:
    int tamanio;
    Nodo<T> *primero;

public:

    Lista();

    ~Lista();

    Lista(T d);

    bool esVacio() {
        return primero == NULL;
    }

    void insertarFin(T d);

    void insertarPrincipio(T d);

    void insertarEn(int pos, T d);

    int getTamanio();

    int eliminar(int pos);

    int buscar(T d);

    void imprimir();

    T getDato(int pos, int *err);

    T getDato(int pos);

    int setDato(int pos, T d);

};

#endif //LISTA_LISTA_H

