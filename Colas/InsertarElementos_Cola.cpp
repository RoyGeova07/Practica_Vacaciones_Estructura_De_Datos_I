//para insertar elementos en una cola, hay q seguir 3 pasos

//1. crear espacio en memoria para el nuevo nodo
//2. asignar ese nuevo nodo al dato que queremos insertar 
//3. asignar los punteros frente  y fin hacia el nuevo nodo

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo *siguiente;

};

bool ColaVacia(Nodo *frente)
{

    return (frente==nullptr) ? true:false;

}

void InsertarCola(Nodo *&frente, Nodo *&fin, int n)
{

    Nodo *nuevo_nodo=new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=nullptr;

    if(ColaVacia(frente)){

        frente=nuevo_nodo;

    }else{

        fin->siguiente=nuevo_nodo;

    }
    fin=nuevo_nodo;

    cout<<"Elemento "<<n<<" insertado a la cola correctamente."<<endl;

}