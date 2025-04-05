#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo
{

    int dato;
    Nodo *siguiente;

};


void AgregarPilas(Nodo *&Pila,int n)
{

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=Pila;
    Pila=nuevo_nodo;

    cout<<"Elemento "<<n<<" agregado a la pila exitosamente"<<endl;

}

//para poder eliminar elementos de la pila hay q seguir 4 pasos
//1. crear una variable de tipo auxiliar  de tipo nodo

//2. Igualar el n a auxiliar ->dato

//3. pasar pila a siguiente nodo

//4. elimiar auxiliar

//ahora los parametros de scar elementos de la pila, cambia un poco
//el tipo de int los pasamos por referencia,porque va a variar.
void EliminarElementosPila(Nodo *&Pila,int &n)
{

    Nodo *auxiliar=Pila;

    n=auxiliar->dato;

    Pila=auxiliar->siguiente;

    delete auxiliar;

}

int main(){

    Nodo *pila=nullptr;
    int dato;

    cout<<"Ingrese un numero: ";
    cin>>dato;
    AgregarPilas(pila,dato);

    cout<<"Ingrese otro numero: ";
    cin>>dato;
    AgregarPilas(pila,dato);

    cout<<"\nSacando los elementos de la pila: "<<endl;
    while(pila!=nullptr)
    {

        EliminarElementosPila(pila,dato);
        if(pila!=nullptr)
        {

            cout<<dato<<" -> ";

        }else{

            cout<<dato<<" -> null";

        }

    }

    return 0;
}
