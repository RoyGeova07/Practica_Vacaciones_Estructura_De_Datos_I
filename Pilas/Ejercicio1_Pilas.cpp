//hacer un programa que para agregar numeros enteros a una pil,a hasta que el usuario lo decida
//despues mostrar todos los elementos de la pila

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo
{

    int dato;
    Nodo *siguiente;

};

void AgregarAPila(Nodo *&pila,int n){

    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=pila;
    pila=nuevo_nodo;

    cout<<"\tElemento "<<n<<" agregado a la pila exitosamente"<<endl;

}

void EliminarElementosPila(Nodo *&pila,int &n){

    Nodo *auxiliar=pila;
    n=auxiliar->dato;
    pila=auxiliar->siguiente;
    delete auxiliar;

}

int main(){

    Nodo *pila=nullptr;
    int dato;
    char respuesta;

    do{

        cout<<"Ingrese un numero: ";
        cin>>dato;
        AgregarAPila(pila,dato);

        cout<<"\nDesea agregar otro numero a pila? (s/n): ";
        cin>>respuesta;

    }while(respuesta=='s'||respuesta=='S');

    cout<<"\nSacando todos los elemento de la pila: "<<endl;
    while(pila!=nullptr)//mientras no se el final de la pila
    {
        EliminarElementosPila(pila,dato);
        if(pila!=nullptr)
        {

            cout<<dato<<" -> ";

        }else{

            cout<<dato<<" -> null";

        }
        



    }

}