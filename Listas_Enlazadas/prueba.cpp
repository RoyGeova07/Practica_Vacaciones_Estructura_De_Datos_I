#include<iostream>
using namespace std;

struct Nodo
{
    
    Nodo*siguiente;
    int dato;

};


void Insertar(Nodo*&lista,int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;

    Nodo*aux1=lista;
    Nodo*aux2;

    while ((aux1!=nullptr)&&(aux1->dato<n))
    {
        
        aux2=aux1;
        aux1=aux1->siguiente;

    }
    if(lista==aux1)
    {

        lista=nuevo_nodo;

    }
    nuevo_nodo=nuevo_nodo->siguiente;

}

void Mostrar(Nodo*lista)
{

    Nodo*actual=lista;

    while (actual!=nullptr)
    {
        
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;

    }
    

}

int main()
{

    Nodo*lista=nullptr;
    int opcion,dato;

    do
    {
        
        cout<<"\n====MENU====\n";
        cout<<"1. Insertar Elementos lista\n";
        cout<<"2. Mostrar Elementos lista\n";
        

    } while (opcion!=4);
    

}