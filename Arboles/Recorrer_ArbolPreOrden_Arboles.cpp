#include<iostream>
using namespace std;

struct Nodo
{
    
    int dato;
    Nodo*Derecha;
    Nodo*Izquierda;

};

Nodo*Arbol=nullptr;

Nodo*CrearNodo(int n)
{

    Nodo*nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->Derecha=nullptr;
    nuevo_nodo->Izquierda=nullptr;

    return nuevo_nodo;

}

void Insertar(Nodo*&arbol,int n)
{

    if(arbol==nullptr)
    {

        Nodo*nuevo_nodo=CrearNodo(n);
        arbol=nuevo_nodo;

    }else{

        int ValorRaiz=arbol->dato;

        if(n<ValorRaiz)
        {

            Insertar(arbol->Izquierda,n);

        }else{

            Insertar(arbol->Derecha,n);

        }

    }

}

void MostrarArbol(Nodo*arbol,int contador)
{

    if(arbol==nullptr)
    {

        return;

    }else{

        MostrarArbol(arbol->Derecha,contador+1);

        cout<<"   ";

    }
    cout<<arbol->dato<<endl;
    MostrarArbol(arbol->Izquierda,contador+1);

}

bool Buscar(Nodo*arbol,int n)
{

    if(arbol==nullptr)
    {

        cout<<"\nNo hay elementos arbol\n";
        return;

    }else if(arbol->dato==n){

        return true;

    }else if(n<arbol->dato){

        return Buscar(arbol->Izquierda,n);

    }else{

        return Buscar(arbol->Derecha,n);

    }

}

//p