//
// Created by Francisco on 11/04/2016.
//


#include <iostream>
#include <string>
#include "Cola.h"

using namespace std;
//////////////////////////////////////////////Metodos Clase/////////////////////////////////////////////////////////////
template<class T>
Cola<T>::Cola() {
    nodoFront = NULL;
    nodoBack = NULL;
    nodoIni=NULL;
    nodoFin=NULL;
}

template<class T>
Cola<T>::Cola(T d) {
    nodoFront = new Nodo<T>(d);
    nodoBack = nodoFront;
}


template<class T>
bool Cola<T>::esVacia() {
    return nodoFront == NULL;
}

template<class T>
void Cola<T>::encolar(T d) {
    Nodo<T> *newNodo = new Nodo<T>(d);

    if (esVacia())
        nodoFront = newNodo;
    else
        nodoBack->setNext(newNodo);

    nodoBack = newNodo;
}

template<class T>
T Cola<T>::desencolar(int *e) {
    Nodo<T> *nodoTmp;
    T v;

    nodoTmp = nodoFront;
    if (esVacia()) {
        *e = 1;
        return v;
    }

    nodoFront = nodoFront->getNext();
    v = nodoTmp->getDato();
    delete (nodoTmp);

    if (esVacia())
        nodoBack = NULL;

    *e = 0;
    return v;
}

template<class T>
T Cola<T>::desencolar() {
    int err;
    return desencolar(&err);
}

template<class T>
Cola<T>::~Cola() {
    int e;
    while (!esVacia()) {
        desencolar(&e);
    }
}
/////////////////////////////////////////////Mis metodos////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////Cantidad de elementos (not work)/////////////////////////////////////////
template <class T>
int Cola<T>::Cantidad()
{
    Nodo<T> *n = nodoFront;
    int cant=0;
    while(this->nodoFront->getNext()!=NULL)
    {

        cant++;
       this->nodoFront = this->nodoFront->getNext();

    }
    nodoFront = n;
    return cant;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////Ordena Con dos colas Auxiliares/////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Cola<T>::encolarP(T d, int p)
{
    Nodo<T> *newNodo = new Nodo<T>(d,p);

    if (esVaciaS())
        nodoIni = newNodo;
    else
        nodoFin->setNext(newNodo);

    nodoFin = newNodo;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
 Cola<T>::Cola(T d, int p)
{
    nodoIni = new Nodo<T>(d,p);
    nodoFin = nodoIni;
}
/////////////////////////////////////////////////////////////////////////// ////////////////////////////////////////////

template <class T>
T Cola<T>::desencolarS(int *e)
{
    Nodo<T> *nodoTmp;
    T v;

    nodoTmp = nodoIni;
    if (esVaciaS()) {
        *e = 1;
       return 0;
    }
    nodoIni = nodoIni->getNext();
    v = nodoTmp->getDato();
    delete (nodoTmp);

    if (esVaciaS())
        nodoFin = NULL;

    *e = 0;
    return v;
}
///////////////////////////////////////////Desencolar con saldo///////////////////////////////////////////////////////
template <class T>
T Cola<T>::desencolarS()
{
    int err;
    return desencolar(&err);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool Cola<T>::esVaciaS() {
    return nodoIni == NULL;

}
///////////////////////////////////////////Desencolar con saldo/////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template
class Cola<float>;

template
class Cola<char>;

template
class Cola<int>;

template
class Cola<double>;


template <class T>
void Cola<T>::insert(T a, int p)
{
    Nodo<T> *temp;
    Nodo<T>*aux;
    Nodo<T>*aux2;

    temp = new Nodo<T>(a,p);
    temp->setDato(a);
    temp->setPrioridad(p);
    if(esVaciaS()||p < nodoIni->getPrioridad())
    {
            temp->setNext(nodoIni);
            nodoIni = temp;
    }
    else
    {
        aux = nodoIni;

        while(aux->getNext()!=NULL&&aux->getNext()->getPrioridad()<= p)
        {
                aux = aux->getNext();

        }
        temp->setNext(aux->getNext());
        aux->setNext(temp);
    }
}
template <class T>
void Cola<T>::mostrar()
{
    Nodo<T> *ptr;
    ptr= nodoIni;

    if(nodoIni == NULL)
    {
        std::cout <<"Cola Vacia \n";
    }
    else
    {

        while(ptr != NULL)
        {
            std::cout<<"Priodidad :";
            std::cout<<ptr->getPrioridad();
            std::cout<<"     Item:  $ ";
            std::cout<<ptr->getDato()<<std::endl;

            ptr = ptr->getNext();
        }

    }
}
template <class T>
void Cola<T>::AddInCola(T dato, int parametro)
{
    Nodo<T> *temp = new Nodo<T> (dato,parametro);
    Nodo<T> *aux = nodoIni;

    if (esVaciaS()/*||parametro < nodoIni->getPrioridad()*/)
   {
       nodoIni = temp;
       nodoFin = temp;
   }
    else
    {


        if(aux->getPrioridad()< parametro)
        {
            nodoIni->setNext(temp);
        }
        else
        {
            nodoFin->setNext(temp);
        }
    }


}


