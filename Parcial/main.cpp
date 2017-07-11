#include <iostream>
#include "Pila.h"
#include "Lista.h"
#include <string>
#include "Cola.h"


using namespace std;

string Darvuelta(string frase[],int cPalabras);

int Suma(int umbral,Cola<int> lis);

int main() {
    int cons,cantP,num,umbral,cant2;
    Cola<int> ej3;
    string palabra;
    string frase[10];



    do
    {
        cout << "Ingrese una Opcion"<<endl;
        cout << "Ej1"<<endl<< "Ej2"<<endl<< "Ej3"<<endl<< "4- Salir"<<endl;
        cin >> cons;
        switch(cons)
        {
            case 1:
                cout <<"ingrese cantidad de Palabras de la frase"<<endl;
                cin >> cantP;

                for (int i = 0; i < cantP; ++i)
                {
                    cout << "Palabra:   ";
                    cin >> palabra;
                    frase[i]=palabra;
                }
                Darvuelta(frase,cantP);
               // cout << Darvuelta(frase,cantP);

                break;
            case 2:
                //
                break;
            case 3:

                cout <<"ingrese cantidad de Numeros a ingresar"<<endl;
                cin >> cant2;
                for (int j = 0; j < cant2; ++j)
                {
                    cout  << "Cola pos["<<j+1<<"]:   " ;
                    cin >> num;
                    ej3.encolar(num);
                }
                cout <<"ingrese umbral"<<endl;
                cin >> umbral;
                cout<<Suma(umbral,ej3);
                break;
            case 4:
                cout << "fin"<<endl;
        }

    }while(cons !=4);
}
string  Darvuelta(string frase[],int cPalabras)
{
    Pila<string> ej1;
    for (int i = 0; i < cPalabras; ++i)
    {
        ej1.push(frase[i]);
    }

    for (int j = 0; j < cPalabras; ++j) {
        cout << ej1.pop()<<" ";
    }
}
int Suma(int umbral,Cola<int> lis)
{
    int fn=0;
    int aux;
    Cola<int> t =lis;
    while(!t.esVacia())
    {
       aux = t.desencolar();
       if(aux > umbral)
       {
           fn= fn + aux;
       }
    }
   return fn;
}